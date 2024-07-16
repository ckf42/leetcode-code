BEGIN {
    PROCINFO["sorted_in"] = "@ind_num_asc"  # gawk extension
}

{
    for (i = 1; i <= NF; ++i)
        if ($i ~ /^[0-9]./) d[int($i)] = 1
}

END {
    for (n in d) {
        res = res sep n
        sep = ", "
    }
    print res
}
