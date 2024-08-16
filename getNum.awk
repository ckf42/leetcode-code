BEGIN {
    PROCINFO["sorted_in"] = "@ind_num_asc"  # gawk extension
}

{
    for (i = 1; i <= NF; ++i)
        match($i, /^sol\/([0-9]+)\//, m)
        if (m[0]) {
            d[int(m[1])] = 1
        }
}

END {
    for (n in d) {
        res = res sep n
        sep = ", "
    }
    print res
}
