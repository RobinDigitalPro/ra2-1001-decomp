import itertools
import json
from pathlib import Path
root = Path(__file__).resolve().parent
s = json.loads((root/"queue28b.json").read_text(encoding="utf-8"))
anchor = "int Extract_Compressed_Events(void *buf, int bufsize) //"
def options(name, baseline, additions):
    return {"name":name,"options":[{"label":"input","edits":[]}] + [{"label":label, "edits":e} for label,e in additions]}
base = (root/"queue.cpp").read_bytes().decode("latin-1").replace("\r\n","\n")
target = base[base.index(anchor):base.index("}\t// end of Extract_Compressed_Events")]
additions = [
("packet byte base", [("int pos = 0;", "char *packet = (char *)buf;\n\tint pos = 0;"),("((char *)buf)", "packet"),("((unsigned char *)buf)", "((unsigned char *)packet)")]),
("payload start", [("switch (eventdata.Type) {","char *payload = ((char *)buf) + pos + size_of(EventClass, Type);\n\t\t\tswitch (eventdata.Type) {"),("((char *)buf) + pos + size_of(EventClass, Type),","payload,"),("((char *)buf) + pos + size_of(EventClass, Type) + datasize,","payload + datasize,")]),
("signed list ID", [("case (EventClass::MEGAMISSION):","case (EventClass::MEGAMISSION): {"),("if (numunits > 1) {", "int listID = (char)eventdata.Data.MegaMission.Unused_6;\n\t\t\t\t\tif (numunits > 1) {"),("(char)eventdata.Data.MegaMission.Unused_6 + house * 8","listID + house * 8"),("house, units, (char)eventdata.Data.MegaMission.Unused_6", "house, units, listID"),("Frame, (char)eventdata.Data.MegaMission.Unused_6, house", "Frame, listID, house"),("(char)eventdata.Data.MegaMission.Unused_6, units * 5", "listID, units * 5"),("\n\t\t\t\tdefault:","\n\t\t\t\t}\n\t\t\t\tdefault:")]),
("incoming type", [("if (event->Type != EventClass::FRAMESYNC) {","const unsigned char incoming = event->Type;\n\t\tif (incoming != EventClass::FRAMESYNC) {"),("if (event->Type == EventClass::FRAMEINFO)", "if (incoming == EventClass::FRAMEINFO)"),("else if (event->Type == EventClass::MEGAMISSION)", "else if (incoming == EventClass::MEGAMISSION)"),("eventdata.Type = event->Type;", "eventdata.Type = incoming;")]),
("fixed header size", [("int pos = 0;", "const int commonBytes = offsetof(EventClass, Data) - size_of(EventClass, Type);\n\tint pos = 0;"),("(offsetof(EventClass, Data) -\n\t\t\t\t\t\t size_of(EventClass, Type))","commonBytes"),("(offsetof(EventClass, Data) -\n\t\t\t\t\t\t\t\tsize_of(EventClass, Type))","commonBytes")]),
("current packet size", [("pos += (datasize + size_of(EventClass, Type));\n\t\t\tleftover -= (datasize + size_of(EventClass, Type));", "const int packetBytes = datasize + size_of(EventClass, Type);\n\t\t\tpos += packetBytes;\n\t\t\tleftover -= packetBytes;")]),
]
def combine(ix):
    t = target
    for i in sorted(ix, key=lambda n: 10 if n==0 else n):
        for old,new in additions[i][1]:
            if old not in t:
                raise ValueError((i,old))
            t=t.replace(old,new)
    return [[target,t]]
sets=[(i,) for i in range(len(additions))]+[(0,1),(1,2),(2,3),(0,1,2),(1,2,3),(1,2,3,4),(0,1,2,3,4),(0,1,2,3,4,5)]
s["choices"] = [options("packet values", "", [(" + ".join(additions[i][0] for i in ix),combine(ix)) for ix in sets]),s["choices"][2],s["choices"][4],s["choices"][5]]
(root/"queue28c.json").write_text(json.dumps(s,indent=2),encoding="utf-8")

