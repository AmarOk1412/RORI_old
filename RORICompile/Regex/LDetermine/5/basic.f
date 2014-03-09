^(salut|bonjour|bonsoir|hei|hi|hello)( rori|)$
function/repliques/sayHello
(au(| |-)revoir|(à|a) la prochaine|bonne soir(ée|ee)|good( |-)bye|bye|j.y.vais)
function/repliques/sayGoodbye
(é|e)cran.noir|black.screen|sleep|dor(s|t)
function/repliques/blackScreen
(^sourdine$|^muet$|^mute$|^coupe le son$|^no sound please$)
function/repliques/mute
(ver(r|)ouil(l|)(e (l.ordi|le pc|l'(é|e)cran|toi)|age)|bloque.toi)|^lock
function/repliques/lock
^stop.{0,20}musi(c|que)
function/repliques/music --SENTENCESEND--
^(joue de la |lance.{0,20}|met.{0,20}|)musi(c|que)
function/repliques/music --SENTENCESEND--
(ouvre|lance|run|exec|open).{0,30}--LOGICIEL--
function/repliques/execSoft
(stop|close|ferme|arrete).{0,30}--LOGICIEL--
function/repliques/stopSoft
^quel es(t) ton.{0,20}(â|a)ge|^how old are you
function/repliques/age
^quel.{0,20}(â|a)ge.{0,20}(tu)
function/repliques/age
quan.{0,10}(existe|tu né|(t'|tu).{0,30}cr(éé|ee))|Since when.{0,100}exist|when.{0,100}create
function/repliques/age
puis.je.{0,100}(source|code)|sous.quelle.licence|(where |)can i read.{0,100}code|under.{0,100}license
function/repliques/license
^(pr(é|e)sente|qui).{0,30}(amarok|ton cr(é|e)ateur|t'a(s) cr(éé|ee))|who.{0,100}(create|is amarok|programmer|creator)
function/repliques/creator
(remet le |)son|sound
function/repliques/sound
^(tu peux|)chante(r|)|sing
function/repliques/song
