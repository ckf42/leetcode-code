do {|x| git add . ; git commit -m $x} (git status | gawk -f getNum.awk)
