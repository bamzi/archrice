#export FILE="ranger"
#export TERMINAL="st"
# #---Basic Definitions---# #
for_window [class="^.*"] border pixel 2
gaps inner 10
gaps outer 10
set $term --no-startup-id $TERMINAL
set $mod Mod4
set $mod1 Mod1
font pango: Noto Sans Mono 10
floating_modifier $mod
# #---Dropdown Windows---# #
# General dropdown window traits. The order can matter.
for_window [instance="dropdown_*"] floating enable
for_window [instance="dropdown_*"] move scratchpad
for_window [instance="dropdown_*"] sticky enable
for_window [instance="dropdown_*"] scratchpad show
for_window [instance="dropdown_tmuxdd"] resize set 625 450
for_window [instance="dropdown_dropdowncalc"] resize set 800 300
for_window [instance="dropdown_tmuxdd"] border pixel 3
for_window [instance="dropdown_dropdowncalc"] border pixel 2
for_window [instance="dropdown_*"] move position center

bar {
	font -misc-fixed-medium-r-normal--13-120-75-75-C-70-iso10646-1
	font pango:Noto Sans Mono 10 
	status_command i3blocks
	position top
	mode dock
	modifier None
	tray_output primary
}

# #---Basic Bindings---# #
bindsym $mod+d exec dmenu_run -fn 'Awesome-11' -nb '#000000' -nf '#A9D3DE' -sb '#1146ac' -sf '#a9d3de'
bindsym $mod+f		 	floating toggle
bindsym $mod+l			layout toggle
# bindsym $mod+space		focus mode_toggle
bindsym $mod+o			exec --no-startup-id /home/rishabh/.config/i3/minopen
bindsym $mod+Escape		workspace prev
bindsym $mod+space 		exec urxvt -e ncmpcpp
bindsym $mod+Shift+b		exec /usr/bin/qute/qutebrowser
bindsym $mod+Ctrl+b		exec --no-startup-id feh --randomize --bg-scale /home/rishabh/Pictures/background/*
bindsym $mod+r			exec urxvt -e ranger
bindsym $mod+Shift+Escape 	exec --no-startup-id /home/rishabh/.config/i3/exit.sh
bindsym $mod+mod1+r		exec /home/rishabh/.config/i3/start_record.sh 
bindsym $mod+Ctrl+r		exec /home/rishabh/.config/i3/stop_record.sh
bindsym $mod+Shift+Tab		workspace back_and_forth
bindsym Print			exec --no-startup-id /home/rishabh/.config/i3/screenshot.sh
bindsym $mod+Shift+Print		exec --no-startup-id /home/rishabh/.config/i3/screenshot-rect.sh
bindsym $mod+F3			exec --no-startup-id /home/rishabh/.local/bin/i3cmds/dmenumount
bindsym $mod+F4			exec --no-startup-id /home/rishabh/.local/bin/i3cmds/dmenuumount
bindsym $mod1+F4 		[con_id="__focused__" instance="^(?!dropdown_).*$"] kill
bindsym Caps_Lock		exec --no-startup-id pkill -RTMIN+21 i3blocks
bindsym $mod+m			exec urxvt -e neomutt
bindsym $mod+Ctrl+d		exec --no-startup-id /home/rishabh/.local/bin/i3cmds/display-select.sh
#STOP/HIDE EVERYTHING:
bindsym $mod+Shift+Delete	exec --no-startup-id lmc truemute ; exec --no-startup-id lmc pause ; exec --no-startup-id pauseallmpv; workspace 0; exec $term -e htop ; exec $term -e $FILE

# #---Letter Key Bindings---# #
bindsym $mod+q			[con_id="__focused__" instance="^(?!dropdown_).*$"] kill
bindsym $mod+Shift+q		[con_id="__focused__" instance="^(?!dropdown_).*$"] exec --no-startup-id kill -9 `xdotool getwindowfocus getwindowpid`
bindsym $mod+shift+r		exec --no-startup-id winresize

bindsym $mod+t			split toggle
bindsym $mod+Shift+t		gaps inner current set 15; gaps outer current set 15

bindsym $mod+Shift+y		exec --no-startup-id i3resize left

bindsym $mod+u			exec --no-startup-id ddspawn tmuxdd
bindsym $mod+Shift+u		exec --no-startup-id i3resize down

bindsym $mod+Shift+i		exec --no-startup-id i3resize up

bindsym $mod+Shift+o		exec --no-startup-id i3resize right

bindsym $mod+a			exec --no-startup-id ddspawn dropdowncalc -f mono:pixelsize=24
bindsym $mod+n			exec --no-startup-id mbsync -a
bindsym $mod+s			gaps inner current plus 5
bindsym $mod+Shift+s		gaps inner current minus 5

bindsym $mod+Shift+d		gaps inner current set 0; gaps outer current set 0

set $freeze Distraction-free mode (super+shift+f to reactivate bindings)
mode "$freeze" { bindsym $mod+Shift+f mode "default"
}

bindsym F11			fullscreen toggle
bindsym $mod+Shift+f		mode "$freeze" ;; exec --no-startup-id notify-send "Distraction-free mode activated." "Press Super+Shift+f to return."

bindsym $mod+Left		focus left
bindsym $mod+Right		focus right 

bindsym $mod+z			gaps outer current plus 5
bindsym $mod+Shift+z		gaps outer current minus 5
bindsym $mod+Return		exec urxvt
bindsym $mod+Shift+Return	exec "~/.config/i3/respawn.sh"	
bindsym $mod+c			exec --no-startup-id /home/rishabh/.config/i3/select.sh /home/rishabh/.config/i3/copytext
bindsym $mod+Shift+p		exec --no-startup-id /home/rishabh/.config/i3/select.sh /home/rishabh/.config/i3/paths
bindsym $mod+p			exec --no-startup-id /home/rishabh/.config/i3/select.sh /home/rishabh/.config/i3/work-paths
bindsym $mod+b			bar mode toggle
bindsym $mod+Shift+n		floating toggle; sticky toggle; exec --no-startup-id hover right

# #---Workspace Bindings---# #
bindsym $mod+Home		workspace $ws1
bindsym $mod+Shift+Home		move container to workspace $ws1
bindsym $mod+End		workspace $ws10
bindsym $mod+Shift+End		move container to workspace $ws10
bindsym $mod+Next		workspace next
bindsym $mod+Shift+Next		move container to workspace next
bindsym $mod+Tab		workspace next_on_output
bindsym $mod+XF86Back		workspace prev
bindsym $mod+Shift+XF86Back	move container to workspace prev
bindsym $mod+XF86Forward	workspace next
bindsym $mod+Shift+XF86Forward	move container to workspace next
bindsym $mod+semicolon		workspace next
bindsym $mod+h			split vertical ;; exec $term
bindsym $mod+v			split horizontal ;; exec $term
bindsym $mod+Shift+slash	kill
bindsym $mod+backslash		workspace back_and_forth

set $ws1 "1"
set $ws2 "2"
set $ws3 "3"
set $ws4 "4"
set $ws5 "5"
set $ws6 "6"
set $ws7 "7"
set $ws8 "8"
set $ws9 "9"
set $ws10 "10"

# switch to workspace
bindsym $mod+1		workspace $ws1
bindsym $mod+2		workspace $ws2
bindsym $mod+3		workspace $ws3
bindsym $mod+4		workspace $ws4
bindsym $mod+5		workspace $ws5
bindsym $mod+6		workspace $ws6
bindsym $mod+7		workspace $ws7
bindsym $mod+8		workspace $ws8
bindsym $mod+9		workspace $ws9
bindsym $mod+0		workspace $ws10

# move focused container to workspace
bindsym $mod+Shift+1	move container to workspace $ws1
bindsym $mod+Shift+2	move container to workspace $ws2
bindsym $mod+Shift+3	move container to workspace $ws3
bindsym $mod+Shift+4	move container to workspace $ws4
bindsym $mod+Shift+5	move container to workspace $ws5
bindsym $mod+Shift+6	move container to workspace $ws6
bindsym $mod+Shift+7	move container to workspace $ws7
bindsym $mod+Shift+8	move container to workspace $ws8
bindsym $mod+Shift+9	move container to workspace $ws9
bindsym $mod+Shift+0	move container to workspace $ws10

for_window [class="Pinentry"] sticky enable
for_window [class="sent"] border pixel 0px
for_window [window_role="GtkFileChooserDialog"] resize set 800 600
for_window [window_role="GtkFileChooserDialog"] move position center
for_window [title="Default - Wine desktop"] floating enable
# Bindings to make the webcam float and stick.
for_window [title="mpvfloat"] floating enable
for_window [title="mpvfloat"] sticky enable
for_window [title="mpvfloat"] border pixel 0
for_window [title="mpvfloat"] resize set 640 250
for_window [title="mpvfloat"] move position 1567 809
no_focus [title="mpvfloat"]
bindsym $mod+Ctrl+h [title="mpvfloat"] kill
bindsym $mod+$mod1+h exec mpv --title="mpvfloat" av://v4l2:/dev/video0
bindsym $mod+Shift+h exec urxvt -e htop
# #---Function Buttons---# #
bindsym $mod+F2		restart

# #---Arrow Keys---# #
bindsym $mod+Ctrl+Left		move workspace to output left
bindsym $mod+Down		focus down
bindsym $mod+Ctrl+Down		move workspace to output down
bindsym $mod+Up			focus up
bindsym $mod+Ctrl+Up		move workspace to output up
bindsym $mod+Ctrl+Right		move workspace to output right
bindsym $mod+Shift+Left		move left
bindsym $mod+Shift+Down		move down
bindsym $mod+Shift+Up		move up
bindsym $mod+Shift+Right 	move right

bindsym XF86AudioRaiseVolume exec --no-startup-id "pactl set-sink-mute 0 0 && ~/.config/i3/vol_up.sh" 
bindsym XF86AudioLowerVolume exec --no-startup-id "pactl set-sink-mute 0 0 && pactl -- set-sink-volume 0 -5%;pkill -RTMIN+10 i3blocks" 
bindsym XF86AudioMute exec --no-startup-id "pactl set-sink-mute 0 toggle;pkill -RTMIN+10 i3blocks" 

# Sreen brightness controls
bindsym XF86MonBrightnessUp exec "xbacklight -inc 10;pkill -RTMIN+11 i3blocks"
bindsym XF86MonBrightnessDown exec "xbacklight -dec 10;pkill -RTMIN+11 i3blocks" 

bindsym XF86PowerOff exec ~/.config/i3/power.sh

# Background
exec --no-startup-id feh --randomize --bg-scale '/home/rishabh/Pictures/background/*'

# Mouse Configurations
exec --no-startup-id xinput set-prop 13 305 1
exec --no-startup-id xinput set-porp 13 321 {0 1}
exec --no-startup-id xinput set-prop 13 313 1

# Terminal Transparent

# Top bar

# Netowrk Manager
exec --no-startup-id nm-applet

# Notification
exec --no-startup-id dunst -config /home/rishabh/.config/dunst/dunstrc

# Lock Screen
exec --no-startup-id xautolock -time 10 -locker '~/.config/i3/lock.sh'