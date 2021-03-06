________________________________________________________________

#### <p align=center>"I’ve never thought philosophy would be so deadly."</p> ####
________________________________________________________________

  #### Проект состоит в решении [задачи об обедающих философах](https://ru.wikipedia.org/wiki/%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0_%D0%BE%D0%B1_%D0%BE%D0%B1%D0%B5%D0%B4%D0%B0%D1%8E%D1%89%D0%B8%D1%85_%D1%84%D0%B8%D0%BB%D0%BE%D1%81%D0%BE%D1%84%D0%B0%D1%85 "Ссылка") путем использования многопоточности и процессов в С.
  
  
<details>
<summary>Описание задачи</summary>
Несколько безмолвных философов сидят вокруг круглого стола, перед каждым философом стоит тарелка спагетти. Вилки лежат на столе между каждой парой ближайших философов.
Каждый философ может есть, спать, или размышлять. Как только филосов заканчивает есть он сразу засыпает. Проснусшись он принимается за размышления. Приём пищи не ограничен количеством оставшихся спагетти — подразумевается бесконечный запас. Тем не менее, философ может есть только тогда, когда держит две вилки — взятую справа и слева (альтернативная формулировка проблемы подразумевает миски с рисом и палочки для еды вместо тарелок со спагетти и вилок).
Каждый философ может взять ближайшую вилку (если она доступна) или положить — если он уже держит её. Взятие каждой вилки и возвращение её на стол являются раздельными действиями, которые должны выполняться одно за другим.
Вопрос задачи заключается в том, чтобы разработать модель поведения (параллельный алгоритм), при котором ни один из философов не будет голодать, то есть будет вечно чередовать приём пищи и размышления.
</details>

Задача сформулирована таким образом, чтобы иллюстрировать проблему избежания взаимной блокировки (наступление дедлока).  К решению данной проблемы есть три подхода: 
1. Иерархия ресурсов - thread & mutex ([link](https://github.com/Tenagrim/PhiloSimulation/tree/main/simulation/phreads_mutexes "Ссылка"));
2. Официант - thread & semaphore ([link](https://github.com/Tenagrim/PhiloSimulation/tree/main/simulation/pthreads_semaphores "Ссылка"));
3. Решение на основе монитора - fork & semaphore ([link](https://github.com/Tenagrim/PhiloSimulation/tree/main/simulation/processes_semaphores "Ссылка"));

При запуске программы необходимо подать следующие аргументы:
1. Количество философов; (столько же будет вилок на столе)
2. Время до смерти в милисекундах;
3. Время еды в милисекундах;
4. Время сна в милисекундах;
5. Сколько раз должен поесть каждый философ; (опциональный аргумент)

После каждого приема пищи, философ является сытым. Если философ не поест по истечению времени до сметри (второй аргумент), он погибнет. Программа завершается если: любой философ умер от голода или все философы поели указанное количество раз.

Сообщение о смерти философа должно быть последним. Далее не должно быть никаких сообщений, программа завершается.<br><br>
![alt text](https://github.com/Tenagrim/PhiloSimulation/blob/main/img/out.gif?raw=true)

Проект написан по стандарту С 98.
