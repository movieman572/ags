#Building the engine on any 32 bit Linux
On Debian/Ubuntu, building a package (see below) is recommended.
On other distributions, install development files of the following
libraries. (In brackets are versions that are known to work, but other
versions should work, too.)

-   Allegro 4 (> 4.2.2)
-   libaldmb (0.9.3)
-   libdumb (0.9.3)
-   libfreetype (2.4.9)
-   libogg (1.2.2-1.3.0)
-   libtheora (1.1.1-1.2.0)
-   libvorbis (1.3.2)

Download the sources with git and compile:

    git clone git://github.com/adventuregamestudio/ags.git
    cd ags
    make --directory=Engine --file=Makefile.linux

The **ags** executable can now be found in the **Engine** folder.


#Building a Debian/Ubuntu package of AGS
While it's not strictly necessary to do this on 32 bit architectures,
it greatly simplifies the installation of AGS on 64 bit architectures.
AGS doesn't work natively on 64 bit, but the development versions of
Debian and Ubuntu will soon support parallel installation of both 32
and 64 bit versions of all required libraries. (This page will be
updated when it works.) Thanks to multiarch, installing AGS on 64 bit
systems will be as easy as on 32 bit systems.


##Getting and updating the sources

###First time
    git clone git://github.com/adventuregamestudio/ags.git
    cd ags
    debian/rules get-orig-source

###Updating (with clean working directory)
    git pull
    debian/rules get-orig-source

###Matching working directory and orig tarball
To build the package, it is important that the working directory has
the same content as the tarball that is created from the git content
with `debian/rules get-orig-source`.

To ensure this, check if the working directory is clean with

    git status

If there are changes, run 

    debian/rules clean 

and/or

    git reset --hard HEAD

If there are still untracked files, delete them manually.

Run `debian/rules get-orig-source` every time the sources change. If
you want to change the sources yourself, you have to commit the
changes to git before running `debian/rules get-orig-source` and
building the package.


##Building the package

###32 bit (i386)

Install build dependencies and devscripts:

    sudo apt-get install devscripts debhelper pkg-config liballegro4.2-dev libaldmb1-dev libfreetype6-dev libtheora-dev libvorbis-dev libogg-dev

Build the package and install it and its dependencies with gdebi:

    cd ags
    debuild
    sudo gdebi ../ags_3.21.1115~JJS-1_i386.deb

###64 bit (amd64)

This part doesn't work like this, until the libdumb package was rebuilt
in Debian/Ubuntu. It will soon work in Debian sid and wheezy and Ubuntu
quantal. This page will be updated once the time has come. 

Enable multiarch:

    sudo dpkg --add-architecture i386
    sudo apt-get update

Install and prepare pbuilder (use the same distribution you are using):

    sudo apt-get install pbuilder
    sudo pbuilder create --distribution sid --architecture i386

This creates an i386 chroot which will be used to build the i386 package
on an amd64 system. pbuilder automatically manages the build dependencies.
The pbuilder base can later be updated with

    sudo pbuilder update

Build the package with pbuilder and install it and its dependencies with gdebi:

    cd ags
    pdebuild
    sudo gdebi /var/cache/pbuilder/result/ags_3.21.1115~JJS-1_i386.deb


#Using the engine

To start an AGS game, just run ags with the game directory or the game
file as parameter, e.g.

    ags /path/to/game

or

    ags game.exe

The configuration file **acsetup.cfg** in the game directory will be used
if present. Sometimes a configuration file coming with a game can cause problems,
so if a game doesn't start, try deleting **acsetup.cfg** first.

For midi music playback, you have to download GUS patches. We recommend
"Richard Sanders's GUS patches" from this address:

http://alleg.sourceforge.net/digmid.html

A direct link is here:

http://www.eglebbk.dds.nl/program/download/digmid.dat

Rename that file to **patches.dat** and place it directly into your home folder.