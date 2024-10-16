<h1 align="center">cokicat's dotfiles — suckless</h1>
<p align="center"><b>Colorscheme: <a href="https://github.com/myagko/nymph.git">nymph</a> by <a href="https://github.com/myagko/">myagko</a></b><p>
<p align="center"><b><a href="">Wallpaper</a></b><p>
<br>

Here are my dotfiles for st and dwm (very lightweight).  
My other dotfiles (like bash and vim dotfiles) are located at [cokicat/dotfiles](https://github.com/cokicat/dotfiles.git).

- **GTK Theme**: [Colloid-Dark-Everforest]()
- **Icon Theme**: [Papirus-Dark]()
- **Font**: [Fira Code Nerd Font]()
- **Cursor Theme**: [Bibata-Modern-Classic]()
- **Launcher**: dmenu

## Install
- [ ] todo
<br>

## dwm
dwm version: 6.8
### License
See `dwm/LICENSE` for more informations.
### Mods
Gaps and borders are showed when only one client with uselessgaps:
```c
//line 1327 in dmw.c

	/* Get number of clients for the client's monitor */
	for (n = 0, nbc = nexttiled(c->mon->clients); nbc; nbc = nexttiled(nbc->next), n++);

	/* Do nothing if layout is floating */
	if (c->isfloating || c->mon->lt[c->mon->sellt]->arrange == NULL) {
		gapincr = gapoffset = 0;
	} else {
		/* Modified by cokicat */
		
		/* Remove border and gap if layout is monocle or only one client */
		//if (c->mon->lt[c->mon->sellt]->arrange == monocle || n == 1) {
		/* Don't remove border and gap if only one client */
		if (c->mon->lt[c->mon->sellt]->arrange == monocle) {
			gapoffset = 0;
			gapincr = -2 * borderpx;
			wc.border_width = 0;
		} else {
			gapoffset = gappx;
			gapincr = 2 * gappx;
		}
	}
```


### Patches used
Patches are in `dwm/patches`.
- actualfullscreen
- cfacts
- cool-autostart
- movestack
- notitle
- uselessgap

## st
st version: 0.9.2
### License
See `st/LICENSE` for more informations.
### Patches used
Patches are in `dwm/patches`.
- blinking_cursor


