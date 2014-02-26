#!/usr/bin/python

import urllib, pycurl, os, sys

def downloadFile(url, fileName):
    fp = open(fileName, "wb")
    curl = pycurl.Curl()
    curl.setopt(pycurl.URL, url)
    curl.setopt(pycurl.WRITEDATA, fp)
    curl.perform()
    curl.close()
    fp.close()

def getGoogleSpeechURL(phrase):
    googleTranslateURL = "http://translate.google.com/translate_tts?tl=en&langpair=en&"
    parameters = {'q': phrase}
    data = urllib.urlencode(parameters)
    googleTranslateURL = "%s%s" % (googleTranslateURL,data)
    return googleTranslateURL

def speakSpeechFromText(phrase):
    googleSpeechURL = getGoogleSpeechURL(phrase)
    downloadFile(googleSpeechURL,"tts.mp3")
    os.system("mplayer tts.mp3 -af extrastereo=0 &")

phrase = ""
for i in range(1, len(sys.argv)):
    phrase += sys.argv[i] + ' '
   
speakSpeechFromText(phrase)
