function fish_mode_prompt
    switch $fish_bind_mode
        case default
            set_color --bold red
            echo '[CMD]'
        case insert
            set_color --bold green
            echo '[INS]'
        case replace_one
            set_color --bold green
            echo '[RPL]'
        case visual
            set_color --bold brmagenta
            echo '[VIS]'
        case '*'
            set_color --bold red
            echo '[???]'
    end
    set_color normal
end
