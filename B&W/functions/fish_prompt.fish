function fish_prompt --description 'Write out the prompt'
	set -l last_status $status

    echo -n ' in '

    echo -n (prompt_pwd)
    echo
    echo -n (whoami)
    echo -n '@'
    echo -n (prompt_hostname)

    if not test $last_status -eq 0
        set_color $fish_color_error
    end

    echo -n ' $ '
    set_color normal
end
