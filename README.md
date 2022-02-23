# VICE with TIME_WAIT workaround patch

This is a VICE fork, with a patch that works around the `TIME_WAIT` port problem - if a user closes VICE directly (rather than via client) during a debugging session, the monitor port (6510) can't be reused for a certain time, preventing further sessions to be executed in the meanwhile.

The problem and patch are described [in a thread](https://sourceforge.net/p/vice-emu/mailman/vice-emu-mail/thread/6c74b5e5-1bde-361a-468a-1af7ff95f304%40Liss.pp.se/#msg37271531) in the VICE mailing list.

Since the most compatible version of VICE with the debugger I use ([Kick Assembler Studio](https://github.com/sanmont/vscode-kickass-studio)) is v3.4, I've based the fork on it.

This repository has only a master branch, which is the v3.4 release commit, with on top two commits, one with the patch, and one with the README. The whole SVN repository history is included, as this is a fork of the [official SVN mirror](https://github.com/VICE-Team/svn-mirror).

## Compiling

The usual compiling procedure applies:

```sh
# Run from the repository root.

cd vice
./autogen.sh
./configure --config-cache --enable-cpuhistory --enable-external-ffmpeg --disable-rs232 --disable-ipv6 --disable-realdevice
make -j $(nproc)

src/x64sc
```

The configuration flags above are the one I use, and they're not intended to be universal; for informations about all the flags, the descriptions can be found in the output of `./configure`.

For those compiling v3.6, note that some files need to be copied in order for the emulator to work:

- source: `$repo/vice/vice/data/GLSL/`
- files: `bicubic.frag`, `bicubic-interlaced.frag`, `builtin.frag`, `builtin-interlaced.frag`, `viewport.vert`
- destination: data directory
