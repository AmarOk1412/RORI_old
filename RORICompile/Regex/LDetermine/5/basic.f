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
^(ajoute|apprend) le mot|add the word
function/repliques/addWord --SENTENCESEND--
comment.{0,30}va(s|).{0,30}(tu|)|how are you
function/repliques/humor
tu.{0,30}va(s|).{0,30}(bien|mal|comment|bof)|are you ok
function/repliques/humor
(c|ç)a.va
function/repliques/humor
tu (devrais|peu(x|t)|dois).{0,40}r(e|é)p.{0,40}cet.{0,30}ques|you.(must|should).answer
function/repliques/div
^((Q|q)uel es(t) ton.{0,30}nom.{0,40})|what.is.your.name|who.are.you|why.RORI|RORI.{0,100}come.from
function/repliques/roriName
^((Q|q)ui e(s|t).{0,4}(vous|tu))
function/repliques/roriName
^((et |d'o(u|ù).vien(s|t) )ton.{0,30}nom)
function/repliques/roriName
^((P|p)ourquoi.{0,40}(RORI|rori|Rori|R.O.R.I.))
function/repliques/roriName
^(((C|c)omment|tu).{0,30}t.{0,10}(ap(p|)el(l|)|nom).{0,30})
function/repliques/roriName
^((T|t)u.{0,30}(jamais|déjà|pas) di(t|s).{0,30}(ton|votre).{0,30}nom)|you.do.{0,100}say.your.name
function/repliques/roriName
(ouvre|lance|joue|test[open|run|recognize).{0,30}arduino
function/repliques/recoArduino
(ouvre|lance|naviguons|run|exec|open).{0,30}(onivox|internet)
function/repliques/onivox
