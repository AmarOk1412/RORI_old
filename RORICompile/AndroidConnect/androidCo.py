import urllib, os

url = 'urlserver/RORI/requeteAndroid.txt'

usock = urllib.urlopen(url)
data = usock.read()
usock.close()

if os.path.isfile("AndroidConnect/androidSay"):
    os.remove("AndroidConnect/androidSay")
mon_fichier = open("AndroidConnect/androidSay", "w")
mon_fichier.write(data)
mon_fichier.close()
