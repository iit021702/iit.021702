Это гит группы 021702 Белорусского Государственного Университета Информатики и Радиоэлектроники.
================================================================================================

Инструкция.
===========

1. Что это и вообще нафига это надо.
------------------------------------

1. Гит - распределенная ситема контроля версий. 
2. Здесь наша группа будет хранить код) 
3. Благодаря гиту удобнее программировать в команде.
4. Тем не менее, не стоит думать, что это в универе задали на дом. Это только по желаню. Кто не хочет - может не ставить. Но если все-таки решит поставить  это ему поможет.

2. Я ничего здесь не понимаю и вообще здесь в первый раз.
---------------------------------------------------------

1. Если вы сидите на винде, то вот набор действий, которые вам надо сделать. http://help.github.com/win-set-up-git
2. Если вы сидите на линуксе, то вот набор действий, которые вам надо сделать. http://help.github.com/linux-set-up-git

### В конечном итоге вы должны добавить ключ из файла id_rsa.pub в гитхаб

3. Что дальше?
--------------

* Винда:

    Открываем Git-GUI(в пуске) нажимем Clone. 
    Вводим в первую строку git@github.com:iit021702/iit.021702.git. 
    Во вторую путь к папке.  Лучше всего D:\iit.021702. Нажимаем OK, вводим yes.

* Линукс:

    cd и потом 
    git clone git@github.com:iit021702/iit.021702.git

4. Каждый должен создать здесь файл со своим именем(чтобы можн было понять, кто разобрался, а кто - нет)
--------------------------------------------------------------------------------------------------------
Чтобы создать в репозитории файл\папку нужно:
1. создать этот файл\папк на диске в папке iit.021702(куда вы "клонировали репозиторий")
2. в консоли гита написать по порядку git add . -> git commit -am 'created file' -> git pull -> git push

4. Об остальном завтра
----------------------
