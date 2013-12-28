zen-thought
===========

About
-----

This is a zen thought-of-the-day aphorism application based on the daily paper calendar by [JoTaiga](http://jotaiga.com/), and modeled after the old <a href="http://en.wikipedia.org/wiki/Fortune_(Unix)">unix fortune application</a>.

Installation
------------

Clone this repo, and use <tt>make</tt>:

```
$ git clone https://github.com/dpapathanasiou/zen-thought.git
$ cd zen-thought
$ make all
$ sudo make install
```

Once installed, it should be accessible from any command line terminal:

```
$ which zen-thought
/usr/local/bin/zen-thought
$ zen-thought

28th

いえいえ
あなたがいてくれたお陰です
本当にありがとう

No, no I'm very indebted to you
Because of you, I am here
Thank you very much
```

Optionally, add these lines to your <tt>~/.bashrc</tt> file (Mac OSX users edit <tt>~/.bash_profile</tt> instead), so that the aphorism appears automatically every time you start a terminal session:

```sh
if [ -x /usr/local/bin/zen-thought ]; then
    /usr/local/bin/zen-thought
fi
```

Font Support
------------

If your computer does not have any Japanese fonts, download and install the [Open IPA fonts](http://ipafont.ipa.go.jp/index.html#en), either "IPAex Mincho", "IPAex Gothic", or both.

Customization
-------------

### Using Your Own Aphorisms File

When run, the application looks for a command line parameter corresponding to a text file.

If none is provided, it uses for the [jotaiga-aphorisms.txt](jotaiga-aphorisms.txt) file installed to the <tt>$(DATADIR)</tt> defined in the [Makefile](Makefile).

To create your own, prepare a text file 31 lines in length, one for each day of the month, with no single line larger than 1,024 bytes in size.

The line number corresponds to the day of the month: i.e., the first line of the file is the saying for the 1st of the month, etc.

Any pipe characters (|) in the text get converted to carriage returns in the output displayed to stdout (this is a shortcut for enabling multiple lines per aphorism while keeping the source data compact).

[The Devil's Dictionary](http://www.gutenberg.org/ebooks/972) by Ambrose Bierce has always been a favorite alternative to the traditional fortunes and quotes.

### Editing the Existing Aphorisms

You can also just edit the existing [jotaiga-aphorisms.txt](jotaiga-aphorisms.txt) file before installing (it was transcribed as faithfully as possible from the original paper version, but please send pull requests to fix any typos).

Acknowledgements
----------------

* [JoTaiga](http://jotaiga.com/) for their [日めくりカレンダー](http://jyotaiga.cart.fc2.com/?sort=&ca=1&rca=&word=&page=&item=213) of aphorisms
* [Felix Cruz](http://felixcrux.com/) for his [Makefile tutorial](http://felixcrux.com/blog/creating-basic-makefile)
* [Information-technology Promotion Agency, Japan](http://www.ipa.go.jp/) for making their fonts open and freely available

