inoticoming
===========

Port of the inoticoming daemon(http://manpages.ubuntu.com/manpages/hardy/man1/inoticoming.1.html) for FreeBSD, this port uses the libinotify-kqueue library for BSD.This has not been tested extensibily.   
Man page from ubuntu.

NAME

       inoticoming - trigger actions when files hit an incoming directory

SYNOPSIS

       inoticoming [ global-options ] directory actions*

DESCRIPTION

       Inoticoming  is  a  daemon  to  watch  a directory with Linux’s inotify
       framework and trigger actions once files with specific names are placed
       in there.

       For  example  it can be used to wait for .changes files uploaded into a
       directory and call reprepro to put them into your repository.

GLOBAL OPTIONS

       --foreground
              Do not fork, but stay in the foreground and log to stderr.

       --logfile filename
              After forking in the background, log to the  specified  filename
              instead of syslog.

       --pid-file filename
              Write the pid of the running instance into filename.

       --initialsearch
              First  search  the  directory  for  files  already  existing and
              process them with the given rules as if they just appeared.   If
              files show up in this inital phase, they may be processed twice,
              but should never be missed.  (Unless they are too many  and  the
              inotify queue overflows).

ACTIONS

       Each  action description is an optional list of options for this action
       (which files to call it for,  what  directory  to  change  into  before
       executing  it,  ...),  followed  by the command and its arguments ended
       with a single ; as argument. Like:
       inoticoming --foreground / --regexp ^v echo There appeared  {}  in  the
       root  directory. \; (Note that the \ before the ; is needed if and only
       if you calling it from a shell or anything else interpreting the  ;  on
       its own).

   ACTION OPTIONS
       --prefix string
              Only  trigger  this  action,  if  the  filename  starts with the
              specified string.

       --suffix string
              Only  trigger  this  action,  if  the  filename  ends  with  the
              specified string.

       --regexp regular expression
              Only  trigger this action, if the filename matches the specified
              regular expression.

       --chdir directory
              Change into directory before executing the  specified  commands.
              (Note  that  since  it  is  a  well-behaved  daemon, its working
              directory is / which will be inherited by all actions).

       --stdout-to-log
              Redirect the command’s output (stdout) to the logfile.

       --stderr-to-log
              Redirect the command’s error output (stderr) to the logfile.

EXAMPLES

       inoticoming --logfile logs/ilog --pid-file  pid  $INCOMINGDIR  --suffix
       .changes  --stderr-to-log reprepro -s -b $REPREPROBASEDIR --waitforlock
       1000 processincoming rulename {} \;
              This will call reprepro for every new .changes file.  Note  that
              giving {} as argument to processincoming (which inoticoming will
              replace with the filename) so that only that  .changes  file  is
              processed  and reprepro will not complain about a possible other
              yet incomplete .changes file is  only  available  starting  with
              reprepro version 2.2.2.

PROBLEMS

       There is no handling of queue overflows yet.

REPORTING BUGS

       Report bugs or wishlist requests to the Debian BTS
       (e.g. by using reportbug inoticoming under Debian)
       or directly to <brlink@debian.org>.

COPYRIGHT

       Copyright © 2007 Bernhard R. Link
       This  is free software; see the source for copying conditions. There is
       NO warranty; not even for MERCHANTABILITY or FITNESS FOR  A  PARTICULAR
       PURPOSE.

