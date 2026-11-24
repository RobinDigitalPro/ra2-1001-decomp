"""Generate the packet-value grid against the supplied queue.cpp and queue28b.json."""
import json
from pathlib import Path
root = Path(__file__).resolve().parent
spec = json.loads((root / "queue28b.json").read_text())
anchor = "int Extract_Compressed_Events(void *buf, int bufsize) //"
base = (root / "queue.cpp").read_bytes().decode("latin-1").replace("\r\n","\n")
body = base[base.index(anchor):base.index("}\t// end of Extract_Compressed_Events")]
def choice(name, edits):
    return dict(name=name,options=[dict(label="input",edits=[]),dict(label=name,edits=edits)])
choices = []
def replacements(name, pairs):
    edits = []
    for old,new in pairs:
        count = body.count(old)
        if not count or (old in new and count>1):
            raise ValueError((name,old,count))
        edits.extend([[old,new,anchor]] * count)
    choices.append(choice(name,edits))
replacements("incoming packet type", [("if (event->Type != EventClass::FRAMESYNC) {","const unsigned char incoming = event->Type;\n\t\tif (incoming != EventClass::FRAMESYNC) {"),("if (event->Type == EventClass::FRAMEINFO)","if (incoming == EventClass::FRAMEINFO)"),("else if (event->Type == EventClass::MEGAMISSION)","else if (incoming == EventClass::MEGAMISSION)"),("eventdata.Type = event->Type;","eventdata.Type = incoming;")])
replacements("event data offset", [("int count = 0;", "const int headerBytes = offsetof(EventClass, Data) - size_of(EventClass, Type);\n\tint count = 0;"),("(offsetof(EventClass, Data) -\n\t\t\t\t\t\t size_of(EventClass, Type))","headerBytes"),("(offsetof(EventClass, Data) -\n\t\t\t\t\t\t\t\tsize_of(EventClass, Type))","headerBytes")])
replacements("packed target count", [("numunits = *(((unsigned char *)buf) + pos + sizeof(eventdata.Type));","numunits = ((unsigned char *)event)[sizeof(eventdata.Type)];")])
replacements("packet length", [("pos += (datasize + size_of(EventClass, Type));\n\t\t\tleftover -= (datasize + size_of(EventClass, Type));","const int packetBytes = datasize + size_of(EventClass, Type);\n\t\t\tpos += packetBytes;\n\t\t\tleftover -= packetBytes;")])
replacements("sender slot base", [("int slot;", "const int slotsPerHouse = 8;\n\tint slot;"), ("house * 8","house * slotsPerHouse")])
replacements("shared packet base", [("int pos = 0;", "char *packet = (char *)buf;\n\tint pos = 0;"),("((char *)buf)", "packet")])
spec["choices"]=choices
(root/"queue28d.json").write_text(json.dumps(spec,indent=2))
