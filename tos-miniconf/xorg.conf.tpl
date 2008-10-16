# WARNING: xserver_xorg_* package deltas make many assumptions about the layout
# of this file.  Changing the indentation or section order is not advisable.

Section "ServerLayout"
    Identifier	"DIET-PC X11 Server"
    Screen	"Screen (vesa)"
    InputDevice	"ScrollMouse"	"CorePointer"
    InputDevice	"PS2Mouse"	"ExtraPointer"
    InputDevice	"SerialMouse"	"ExtraPointer"
    InputDevice	"Keyboard"	"CoreKeyboard"
EndSection

Section "ServerFlags"
    Option	"AllowNonLocalXvidtune"	"on"
    Option	"BlankTime"	"TOS_SCREEN_BLANK_TIME"
    Option	"StandbyTime"	"TOS_SCREEN_STANDBY_TIME"
    Option	"SuspendTime"	"TOS_SCREEN_SUSPEND_TIME"
    Option	"OffTime"	"TOS_SCREEN_OFF_TIME"
EndSection

Section "Files"
    RgbPath	"/usr/X11R6/lib/X11/rgb"
    FontPath	"/usr/X11R6/lib/X11/fonts/misc/:unscaled"
    FontPath	"/usr/X11R6/lib/X11/fonts/75dpi/:unscaled"
EndSection

Section "Module"
    Load	"dbe"
    Load	"extmod"
EndSection

Section "InputDevice"
    Identifier	"Keyboard"
    Driver	"kbd"
    Option	"Protocol"	"Standard"
    Option	"AutoRepeat"	"250 30"
    Option	"XkbKeymap"	"dietpc"
EndSection

# PS/2 or USB mouse with scroll wheel.
# If you are using a scroll mouse under a Linux 2.4 kernel, change "Device" to
# "/dev/psaux".
Section "InputDevice"
    Identifier	"ScrollMouse"
    Driver	"mouse"
    Option	"Protocol"	"IMPS/2"
    Option	"Device"	"/dev/input/mice"
    Option	"Buttons"	"5"
    Option	"ZAxisMapping"	"4 5"
    Option	"AlwaysCore"
EndSection

# Vanilla three-button PS/2 mouse.
Section "InputDevice"
    Identifier	"PS2Mouse"
    Driver	"mouse"
    Option	"Protocol"	"PS/2"
    Option	"Device"	"/dev/psaux"
    Option	"Buttons"	"3"
    Option	"AlwaysCore"
EndSection

# Serial mouse (for really, really old systems).
Section "InputDevice"
    Identifier	"SerialMouse"
    Driver	"mouse"
    Option	"Protocol"	"TOS_MOUSE_PROTOCOL"	# or possibly "MouseSystems"
    Option	"Device"	"TOS_MOUSE_DEVICE"
    Option	"Buttons"	"2"		# 3 for MouseSystems
    Option	"Emulate3Buttons"		# not needed for MouseSystems
    Option	"AlwaysCore"
EndSection

Section "Monitor"
    Identifier	"Monitor"
    Option	"DPMS"
# Newer monitors with EDID can advise X of their limits and preferences via the
# DDC protocol, if your graphics card supports this (which it probably does).
# If your system doesn't support DDC-EDID, you should explicitly state the scan
# rate limits of your monitor below, using values from your monitor manual,
# otherwise X will use defaults that will either produce suboptimal resolution
# and/or refresh rates, or freak out your monitor.
#   HorizSync	31-50
#   VertRefresh	60-90
# Explicit modelines are rarely needed.
# Try uncommenting the modelines below if you have a very old monitor.
#    Modeline	"1024x768" 65 1024 1032 1176 1344 768 771 777 806 -hsync -vsync
#    Modeline	"1024x768" 44.9 1024 1048 1208 1264 768 776 784 817 Interlace
#    Modeline	"800x600"  50 800 856 976 1040 600 637 643 666 +hsync +vsync
#    Modeline	"800x600"  40 800 840 968 1056 600 601 605 628 +hsync +vsync
EndSection

# This section is used as a template by xserver_xorg_* packages.  Identifier
# and Driver are anchor points, don't change their values or position.
Section "Device"
    Identifier	"Video Card (vesa)"
    Driver	"vesa"
    Option	"BackingStore"
EndSection

# This section is used as a template by xserver_xorg_* packages.  Identifier
# and Device are anchor points, don't change their values or position.
Section "Screen"
    Identifier	"Screen (vesa)"
    Device	"Video Card (vesa)"
    Monitor	"Monitor"
# The default colour depth if unspecified will be a pessimistic-but-safe
# driver-specific value.  State the depth explicitly once you know what works
# with the resolution you want and the video memory available.
    DefaultDepth TOS_COLOR_DEPTH
# If you omit a Display section, the driver will use the highest viable
# resolution (probably too high for comfort), and enable lots of odd lower
# resolutions that you won't want and will never use.  Ensure that the Depth
# setting matches the default above.
    SubSection	"Display"
	Depth	TOS_COLOR_DEPTH
	Modes	"TOS_SCREEN_RESOLUTION"
    EndSubSection
EndSection

Section "DRI"
    Mode	0666
EndSection
