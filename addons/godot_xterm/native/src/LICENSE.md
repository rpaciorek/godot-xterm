The code in `pty_unix.cpp` and `pty_unix.h` is taken from the [node-pty project](https://github.com/microsoft/node-pty), which in turn contains code from the [Tmux project](http://tmux.sourceforge.net/).

The code has been modified to remove references to node/V8 and make it compatible with GDExtension. Any copyrightable modifications are released under the [same license](/addons/godot_xterm/LICENSE.md) as the rest of the GodotXterm project.

The text of the node-pty license can be found in [LICENSE_node-pty](./LICENSE_node-pty)
The text of the tmux license can be found in [LICENSE_tmux](./LICENSE_tmux)
