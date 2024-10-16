/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 20;        /* gaps between windows */
static const unsigned int snap      = 16;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Fira Code Nerd Font:size=11" };
static const char dmenufont[]       = "Fira Code Nerd Font:size=11";
static const char col_foreground[]  = "#BCC4C9";
static const char col_foreground2[] = "#5B6265";
static const char col_background[]  = "#1A2023";
static const char col_background2[] = "#252B2E";
static const char col_cyan[]        = "#89B7B0";
static const char *colors[][3]      = {
	/*               fg               bg               border */
	[SchemeNorm] = { col_foreground2, col_background2, col_background2 },
	[SchemeSel]  = { col_foreground,  col_background,  col_cyan  },
};

static const char *const autostart[] = {
	"setxkbmap", "fr", NULL,
	"feh", "--bg-scale", "/home/cokicat/Images/mountain.jpg", NULL,
	"pipewire", NULL,
	"pipewire-pulse", NULL,
	"/home/cokicat/dwm_status.sh", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "١","٢","٣","٤","٥","٦","٧","٨","٩"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      tile },    /* first entry is default */
	{ "",      NULL },    /* no layout function means floating behavior */
	//{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_background2, "-nf", col_foreground2, "-sb", col_cyan, "-sf", col_background, NULL };
static const char *termcmd[]  = { "st", NULL };

#include "movestack.c"
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_Right,  focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Left,   focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_v,      incnmaster,     {.i = -1 } },
	{ MODKEY|ControlMask,           XK_Left,   setmfact,       {.f = -0.05} },
	{ MODKEY|ControlMask,           XK_Right,  setmfact,       {.f = +0.05} },
	{ MODKEY|ControlMask,           XK_Down,   setcfact,       {.f = +0.25} },
	{ MODKEY|ControlMask,           XK_Up,     setcfact,       {.f = -0.25} },
	//{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
	//{ MODKEY,                       XK_Return, zoom,           {0} },
	//{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	//{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	//{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_f,      togglefullscr,  {0} },
	//{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	//{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	//{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	//{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	//{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	//{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Right,    movestack,      {.i = +1 } },
 	{ MODKEY|ShiftMask,             XK_Left,     movestack,      {.i = -1 } },
	TAGKEYS(                        XK_ampersand,                 0)
	TAGKEYS(                        XK_eacute,                    1)
	TAGKEYS(                        XK_quotedbl,                  2)
	TAGKEYS(                        XK_apostrophe,                3)
	TAGKEYS(                        XK_parenleft,                 4)
	TAGKEYS(                        XK_minus,                     5)
	TAGKEYS(                        XK_egrave,                    6)
	TAGKEYS(                        XK_underscore,                7)
	TAGKEYS(                        XK_ccedilla,                  8)
	{ MODKEY|ShiftMask,             XK_e,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

