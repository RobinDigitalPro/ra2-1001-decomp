# bprel.py obj [func-substring] : print S_BPREL32 records of a function (VC6 /Z7)
import sys,struct
d=open(sys.argv[1],'rb').read(); want=sys.argv[2] if len(sys.argv)>2 else 'WinMain'
nsec=struct.unpack_from('<H',d,2)[0]; opt=struct.unpack_from('<H',d,16)[0]
symoff,nsym=struct.unpack_from('<II',d,8)
strtab=symoff+nsym*18
def secname(raw):
    if raw[0:1]==b'/':
        o=int(raw[1:].rstrip(b'\0')); e=d.index(b'\0',strtab+o); return d[strtab+o:e].decode()
    return raw.rstrip(b'\0').decode()
for i in range(nsec):
    h=20+opt+i*40
    name=secname(d[h:h+8]); size,ptr=struct.unpack_from('<II',d,h+16)
    if name!='.debug$S': continue
    p=ptr+(4 if d[ptr:ptr+4]==b'    p=ptr+4; end=ptr+size; inf=False; depth=0; out=[]    p=ptr+4; end=ptr+size; inf=False; depth=0; out=[]    p=ptr+4; end=ptr+size; inf=False; depth=0; out=[]' else 0); end=ptr+size; inf=False; depth=0; out=[]
    while p<end:
        ln,ty=struct.unpack_from('<HH',d,p); body=d[p+4:p+2+ln]
        if ty in (0x100a,0x100b,0x0204,0x0205):  # GPROC32/LPROC32
            nm=body[35:35+body[35-0]] if False else None
            # CV4 S_GPROC32 layout: parent,end,next(4*3),len,dbgstart,dbgend(4*3),typind(4)? VC6: off(4) seg(2) type(4?) flags(1) name
            s=body.rfind(b'\0')
            # find pascal name: last length-prefixed string
            for k in range(len(body)-1,0,-1):
                L=body[k]
                if k+1+L==len(body) or k+1+L==len(body.rstrip(b'\0')):
                    nm=body[k+1:k+1+L].decode('latin1'); break
            else: nm='?'
            if want in nm: inf=True; depth=0; print('PROC',hex(ty),nm)
            elif inf: depth+=1
            else: depth+=0
        elif ty==0x0207 and inf: depth+=1; print('  '*depth+'{block')
        elif ty==0x0006 and inf:
            if depth==0: inf=False
            else: print('  '*depth+'}'); depth-=1
        elif ty==0x1006 and inf:
            off,ti=struct.unpack_from('<iI',body,0); L=body[8]; nm=body[9:9+L].decode('latin1')
            out.append((off,nm)); print('  '*(depth+1)+'%6s %s'%(hex(off),nm))
        p+=2+ln
    if out:
        print('--- sorted by offset')
        for off,nm in sorted(out): print('%7s %s'%(hex(off),nm))
