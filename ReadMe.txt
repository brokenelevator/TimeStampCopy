========================================================================
    TimeStampCopy by Aleksander Lorenc
========================================================================

Program can batch copy timestamps between files.
This program was written and compiled using Microsoft Visual C++ 2010 Express.
Idea to write this program came when I was upgrading my mp3 library, meaning ripping my CD's again but to FLAC.
Potrzeba jest matk¹ wynalazku.
I wanted to keep the dates it was originally ripped but could not find program to do the job.
I needed it to do what I need and do it in batch. None I found did, but reminded me that I can make my own.
In the process I needed to change compiler because this old Borland I had did not cut it.
Thanks to MSDN Library I was able to code what I needed.
During coding number of improvement ideas came to my mind so I coded them too. That is including TimeStampCreator.

/////////////////////////////////////////////////////////////////////////////
Program usage:

tsc [source] [target] [creation] [access] [write]

source - file to read timestamp[s] from
target - file to save timestamp[s] to
creation, access, write - timestamp options:
      c - replace with source file creation timestamp
      a - replace with source file last access timestamp
      w - replace with source file last write(save) timestamp
      x - leave unchanged

Any time you write bad command information about usage is shown.
Examples:
If you want to copy creation timestamp from a.txt file to b.txt file you write following
tsc a.txt b.txt c x x
If want to copy last access timestamp to last save timestamp with the same files as above you write the following
tsc a.txt b.txt x x a

/////////////////////////////////////////////////////////////////////////////
Requirments:

Windows 2000 Professional or above

/////////////////////////////////////////////////////////////////////////////
Other information:

The filenames I was using were non-latin(hangul) and the program failed. This is what I've done to make it work. There might be an easier/better way.
I made a utf-8 without bom batch(.bat) file in Notepad++. First line was "chcp 65001". Then "tsc..."
Then I run it through PowerShell ISE v2. There is command line in lower half. I wrote "./file.bat".

/////////////////////////////////////////////////////////////////////////////
