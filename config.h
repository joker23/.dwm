/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]            = "-*-terminus-medium-r-*-*-12-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#3F3F3F";
//static const char normbgcolor[]     = "#3F3F3F";
static const char normbgcolor[]     = "#000000";
static const char normfgcolor[]     = "#DCDCCC";
static const char selbordercolor[]  = "#3F3F3F";
static const char selbgcolor[]      = "#000000";
//static const char selbgcolor[]      = "#333333";
static const char selfgcolor[]      = "#00DC00";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systrayspacing = 0;   /* systray spacing */
static const Bool showsystray		= True;		/* False means no systray */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "" };

/**
 * this is mianly used as an example just in case I want to use it in the future
 */
static const Rule rules[] = {
	/* class      		instance    title       tags mask     isfloating   monitor */
	{ "Chromium",  		NULL,       NULL,       1 << 7,       False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
//static const char *termcmd[]  = { "xterm", "-fg", "white", "-bg", "black", NULL };
static const char *termcmd[]  = { "urxvt", NULL };
static const char *browsercmd[]  = { "chromium", NULL };
// static const char *sublcmd[] = { "sublime", NULL };
// static const char *pdfcmd[] = { "evince", NULL };
static const char *lockcmd[]  = { "slock", NULL };

static Key keys[] = {
	/* modifier			key			    function	argument*/
	//Command Macros
	{ MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_w,      spawn,          {.v = browsercmd } },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          {.v = lockcmd } },

	//DWM stufff
	{ MODKEY|ShiftMask,             XK_space,  togglebar,      {0} },
	{ MODKEY,                       XK_h,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_g,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_u,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_comma,  setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_period, setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_z,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_x,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_c,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_r,      setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_r,      togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_q,  	   focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_e,      focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_q,      tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_e,      tagmon,         {.i = +1 } },
	
	//Change Desktops
	TAGKEYS(           	XK_a,       				0)
	TAGKEYS(            XK_s,                     	1)
	TAGKEYS(           	XK_d,                       2)
	TAGKEYS(            XK_f,                      	3)
	TAGKEYS(            XK_j,                      	4)
	TAGKEYS(           	XK_k,                      	5)
	TAGKEYS(           	XK_l,                      	6)
	TAGKEYS(           	XK_semicolon,              	7)
	{ MODKEY|ShiftMask, XK_q,      		quit,      	{0} },
	//TODO change the mapping ;qjkx wvz

};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
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


