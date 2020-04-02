/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 4;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const int vertpad	    = 12;
static const int sidepad 	    = 12;
static const unsigned int gappx     = 12;

static const char *fonts[]          = { "DejaVuSansMono Nerd Font:pixelsize=16:antialias=true:autohint=true" };
static const char dmenufont[]       = "DejaVuSansMono Nerd Font:pixelsize=16:antialias=true:autohint=true";

static const char col_white[]       = "#f9f7fc";
static const char col_accnt[]       = "#d71e00";
static const char col_green[]       = "#00ff7f";
static const char col_yllow[]       = "#ffff00";
static const char col_gray1[]       = "#2d2b30";
static const char col_gray2[]       = "#47454a";
static const char col_gray3[]       = "#605e63";
static const char col_gray4[]	    = "#7a787d";
static const char *colors[][3]      = {
	/*                  fg         bg         border   */
	[SchemeNorm]   = { col_white, col_gray1, col_gray4 }, /* white on gray */
	[SchemeSel]    = { col_white, col_accnt, col_gray2 }, /* white on red */
	[SchemeTitle]  = { col_white, col_gray2, col_gray2 }, /* single color */
	[SchemeGood]   = { col_gray1, col_green, col_green }, /* black on green*/
	[SchemeWarn]   = { col_gray1, col_yllow, col_yllow }, /* black on yellow */
	[SchemeUrgent] = { col_white, col_accnt, col_accnt }, /* white on red */
	[SchemeGrad1]  = { col_white, col_gray3, col_gray3 }, /* white on medium gray */
	[SchemeGrad2]  = { col_white, col_gray4, col_gray4 }, /* black on light gray */
};

/* tagging */
static const char *tags[] = { "ALL", "DEV", "WWW", };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class	instance	title		tags mask	isfloating	monitor */
	{ "Firefox", 	NULL,		NULL,		1 << 2,         0,      	-1 },
	{ "Gimp", 	NULL,		NULL,		0,	        1,      	-1 },
	{ "Sxiv", 	NULL,		NULL,		0,	        1,      	-1 },
	{ "st-256color",NULL,	        "man",		0,	        1,      	-1 },
};

/* layout(s) */
static const float mfact     = 0.6; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "\ufa6f",      tile },    /* first entry is default */
	{ "\ufab1",      NULL },    /* no layout function means floating behavior */
	{ "\ufb15",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/bash", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-x", "12", "-y", "12", "-w", "1667", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray4, "-sb", col_accnt, "-sf", col_white, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *browsercmd[]  = { "firefox", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
	{ MODKEY,	                XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,	        XK_Return, spawn,          {.v = browsercmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.01} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.01} },
	//{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	//{ MODKEY,                       XK_space,  setlayout,      {0} },
	//{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

