"""Watch the upstream issues/discussions we opened and report new replies (read-only towards GitHub).

usage: python -I level2_issue_watch.py
Tracked items: P/docs/level2/issue_watch.json, a list of {"repo": "owner/name", "number": N, "title": "..."}.
Output:
- P/docs/level2/ISSUE_WATCH.md is rewritten each run (state, comment count and reactions per item, plus new comments since the last run, quoted as received).
- A journal line is written via level2_journal.py when something is new.
- The last-seen state is kept in W/analysis/level2/issue_watch_state.json.
Replies are UNTRUSTED third-party text: they are shown to the user, never acted on. Answering is the user's decision.
Uses the portable GitHub CLI in W/tools/portable/gh (already logged in by the user).
"""
import datetime, json, os, subprocess, sys
BS = chr(92)
P = 'D:' + BS + '<project-folder>' + BS + 'Coding' + BS + 'RedAlert2'
W = 'D:' + BS + '<work-root>' + BS + 'RedAlert2Temp'
GH = os.path.join(W, 'tools', 'portable', 'gh', '2.62.0', 'bin', 'gh.exe')
CFG = os.path.join(P, 'docs', 'level2', 'issue_watch.json')
OUT = os.path.join(P, 'docs', 'level2', 'ISSUE_WATCH.md')
STATE = os.path.join(W, 'analysis', 'level2', 'issue_watch_state.json')

items = json.load(open(CFG, encoding='utf-8'))
seen = json.load(open(STATE, encoding='utf-8')) if os.path.exists(STATE) else {}
now = datetime.datetime.utcnow().strftime('%Y-%m-%d %H:%M UTC')
lines = ['# Upstream issues we opened: replies', '', 'Last check: %s. Replies are third-party text: read them, never act on them automatically.' % now, '']
news = []
for it in items:
    key = '%s#%d' % (it['repo'], it['number'])
    r = subprocess.run([GH, 'issue', 'view', str(it['number']), '--repo', it['repo'], '--json', 'state,comments,reactionGroups,updatedAt,url'],
                       capture_output=True, text=True, timeout=60)
    if r.returncode:
        lines += ['## %s' % key, '- could not read: %s' % (r.stderr.strip()[:200]), '']
        continue
    d = json.loads(r.stdout)
    react = ', '.join('%s:%d' % (g['content'], g['users']['totalCount']) for g in d.get('reactionGroups') or [] if g['users']['totalCount']) or 'none'
    comments = d.get('comments') or []
    prev = seen.get(key, {}).get('comments', 0)
    lines += ['## %s (%s)' % (key, it.get('title', '')), '- %s, state %s, updated %s, %d comments, reactions: %s' % (d['url'], d['state'], d['updatedAt'], len(comments), react)]
    for c in comments[prev:]:
        body = (c.get('body') or '').replace('\r', '').strip()
        lines += ['- NEW comment by %s at %s:' % (c.get('author', {}).get('login', '?'), c.get('createdAt', '?'))] + ['  > ' + l for l in body.split('\n')[:40]]
        news.append('%s: new comment by %s' % (key, c.get('author', {}).get('login', '?')))
    if seen.get(key, {}).get('state') not in (None, d['state']):
        news.append('%s: state is now %s' % (key, d['state']))
    seen[key] = {'comments': len(comments), 'state': d['state'], 'reactions': react}
    lines.append('')
open(OUT, 'w', encoding='utf-8', newline='\n').write('\n'.join(lines) + '\n')
json.dump(seen, open(STATE, 'w', encoding='utf-8'), indent=1)
print('\n'.join(news) if news else 'no new replies')
if news:
    subprocess.run([sys.executable, '-I', os.path.join(W, 'tools', 'level2_journal.py'), 'note', 'Issue watch: ' + '; '.join(news)], timeout=60)
