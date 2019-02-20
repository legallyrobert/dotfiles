# a dual-line prompt with Vi-mode indicator and no VCS support... yet
#
# rw@macos :: 2/2/CSC230/Assignments
# [CMD]  $ echo "i love unixpr0n"

function zle-line-init zle-keymap-select {
    VICMD="${${KEYMAP/vicmd/$FG[196]%B[CMD]%b}/(main|viins)/$FG[009][INS]}"
    VIMODE=$VICMD
    zle reset-prompt
}

zle -N zle-line-init
zle -N zle-keymap-select

PROMPT='$FG[127]%n$FG[008]@$FG[127]%m$FG[008] :: $FG[009]%4~%{$reset_color%} \

${VIMODE}  $FG[008]$ '
