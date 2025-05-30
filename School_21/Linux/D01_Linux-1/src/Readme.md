## Task 1 (Установка вируталки / образ системы / проверка версии)

**Задача:**

> Проверьте версию Ubuntu, выполнив команду `cat /etc/issue`

1. **Скачиваем вирутал бокс:**![1734810131198](image/Readme/1734810131198.png)
2. **Скачиваем образ линукс:**

![1734812976426](image/Readme/1734812976426.png)

3. **Создание виртуальной машины:**

![1734813112634](image/Readme/1734813112634.png)

4. **Установка пользователя:**

![1734811771467](image/Readme/1734811771467.png)

5. **Выделение памяти и процессоров под машину:**

![1734811827709](image/Readme/1734811827709.png)

6. **Виртуальный жесткий диск под систему:**

![1734811971586](image/Readme/1734811971586.png)

7. **Ввести версию ядра:**

![1734814609441](image/Readme/1734814609441.png)

---

## Task 2 (Создание пользователя / проверка его существования в рядах adm)

**1. Команда `sudo useradd -m user21`**:

![1734815176885](image/Readme/1734815176885.png)

**2. Проверяем что пользователь создался - `cat /ets/passwd:`**

![1734815698600](image/Readme/1734815698600.png)

---

## Task 3 (Работа с сетью и настройка IP)

1. **Установка имени хоста машины.**

   `sudo vim /etc/hostname` - прописываю user-1 и сохраняю.

> **Hostname** - файл который содержит индификатор компьютера в сети (как локальной так и глобальной), аналог  IP.

2. **Изменение часового пояса так как у пензы нет своего региона как я не пытался его изменить поставлена была Москва.**
   ![1734821977392](image/Readme/1734821977392.png)

> `sudo timedate set-timezone Europe/Moscow` - меняю часовой пояс

3. **Выведите имена сетевых интерфейсов с помощью консольной команды.**

![1734822889573](image/Readme/1734822889573.png)

> *lo* (loopback device) – виртуальный интерфейс, присутствующий по умолчанию в любом Linux. Он используется для отладки сетевых программ и запуска серверных приложений на локальной машине. С этим интерфейсом всегда связан адрес  *127.0.0.1* . У него есть dns-имя –  *localhost* .
>
> dns - это система доменных имен, которая преобразует удобные для человека адреса (например, `example.com`) в IP-адреса, которые необходимы для связи между устройствами.

4. **Используйте консольную команду, чтобы получить IP-адрес устройства, с которым вы работаете, от DHCP-сервера. Расшифруйте DHCP в отчете.**
   ![1734824388302](image/Readme/1734824388302.png)

> `ip addr show` -  показывает айпи адреса как внури устройства так и с DHCP.
>
> Вданном случае это  `inet 10.0.2.15/24 brd 10.0.2.255 scope global dynamic enp0s3.`
> `10.0.2.15` - это  **IP-адрес** , который был назначен устройству.
> `/24`  - маска подсети,
>
> DHCP расшифровывается как **Dynamic Host Configuration Protocol** (Протокол динамической конфигурации хоста). Это протокол, который позволяет устройствам в сети автоматически получать IP-адреса и другие сетевые параметры, такие как маска подсети и шлюз по умолчанию, от сервера DHCP.

5. **Определите и отобразите внешний IP-адрес шлюза (ip) и внутренний IP-адрес шлюза, также известный как IP-адрес по умолчанию (gw).**

   `ip route | grep default -  узнать внутренний айпи адрес`

   ![1734825338125](image/Readme/1734825338125.png)

> **via 10.0.2.2** — это IP-адрес шлюза (маршрутизатора) в локальной сети.
> **dev enp0s3** — это интерфейс, через который осуществляется подключение
> **proto dhcp** — указывает, что IP-адрес был назначен через DHCP.
> **metric 100** — это метрика маршрута (используется для определения предпочтительности маршрута).

` curl ifconfig.me`

![1734825913275](image/Readme/1734825913275.png)

> **37.113.18.44** — это внешний IP-адрес шлюза) через которыйустройство подключается к интернету. Этот адрес видим для всех.

6. **Установите статические (заданные вручную, а не полученные от DHCP-сервера) настройки IP, GW, DNS (используйте публичные DNS-серверы, например, 1.1.1.1 или 8.8.8.8). Перезагрузите виртуальную машину. Убедитесь, что статические сетевые настройки (ip, gw, dns) соответствуют заданным в предыдущем пункте.**

1.1 `sudo vim /etc/netplan/00-installer-config.yaml`

1.2

```**bash
network:
  ethernets:
    enp0s3:                 # Имя интерфейса 
      dhcp4: false             # Отключить DHCP
      addresses: [10.0.2.15/24]  # статический IP-адрес
      gateway4: 10.0.2.2     # IP-адрес шлюза (внутренний IP)
      nameservers:
        addresses: [8.8.8.8, 1.1.1.1]         # DNS Cloudflare
version: 2

```

![1734896497048](image/Readme/1734896497048.png)

1.3 `sudo netplan apply - обновление настроек `

1.4 `sudo reboot - перезагрузка системы `

1.5 `ip a` - проверка статического адреса

1.6 `ip route | grep default` - проверка шлюза

1.7 `ping -c 4 1.1.1.1   `

![1734896723467](image/Readme/1734896723467.png)

---

## Task 4 (Oбновление системных пакетов)

1. **Обновите системные пакеты до последней версии.**

   ![1734870154267](image/Readme/1734870154267.png)

---

## Task 5 (Использование команды `sudo`)

1. **Что такое sudo:**

> Команда `sudo` позволяет пользователю временно выполнять команды с правами администратора (root) без необходимости входить в систему как root. 
> Это помогает:
>
>     Работать безопаснее, так как пользователи используют повышенные привилегии только при необходимости.
>
>     Вести учёт всех действий, выполняемых с помощью`sudo`, что делает процесс прозрачным и упрощает контроль.

2. `sudo usermod -aG sudo user-1` и `groups user-1`

![1734870961297](image/Readme/1734870961297.png)

3. `su - user-1`

![1734871938837](image/Readme/1734871938837.png)

`sudo vim /etc/hostname && sudo reboot `

![1734873002957](image/Readme/1734873002957.png)

---

## Task 6 ( Установка и настройка службы времени)

·1. **Выведите время часового пояса, в котором вы в данный момент находитесь:**

![1734873419705](image/Readme/1734873419705.png)

·2. **Вывод следующей команды должен содержать NTPSynchronized=yes:**

![1734873512982](image/Readme/1734873512982.png)

---

## Task 7 (Установка и работа с текстовыми редакторами)

1. **Установите текстовый редактор ****VIM**** (+ любые два других, если вам нравятся ****NANO**** , **MCEDIT**).**

   Вим утановлен по дефолту как  и нано, установил mcedit.

   ```bash
   sudo apt install mc
   ```

![1734874157697](image/Readme/1734874157697.png)

`shift+z+z`

![1734874285994](image/Readme/1734874285994.png)

`cntrl +x +y`

![1734874399276](image/Readme/1734874399276.png)

`f2 + f10`

2. **Используя каждый из трех выбранных редакторов, откройте файл для редактирования, отредактируйте файл, заменив псевдоним на строку «21 School 21», закройте файл, не сохраняя изменения.**

![1734874734252](image/Readme/1734874734252.png)

`esc + :q!`

![1734874853806](image/Readme/1734874853806.png)

`cntrl + x + n`

![1734874970808](image/Readme/1734874970808.png)

`f10 + n`

3. **Используя каждый из трех выбранных редакторов, отредактируйте файл еще раз (аналогично предыдущему пункту), а затем освойте функции поиска по содержимому файла (слову) и замены слова на любое другое.**

![1734875335746](image/Readme/1734875335746.png)

![1734877055159](image/Readme/1734877055159.png)

![1734877462539](image/Readme/1734877462539.png)

`cnrtl + w `

![1734877527348](image/Readme/1734877527348.png)

`cntrl + \`

![1734878090509](image/Readme/1734878090509.png)

`f7`

![1734878120869](image/Readme/1734878120869.png)

`f4`

---

## Task 8 (Установка и базовая настройка сервиса **SSHD**)

1. **Установите службу SSHd.**

![1734878433855](image/Readme/1734878433855.png)

2. **Добавить автоматический запуск службы при каждой загрузке системы.**

   ![1734878566923](image/Readme/1734878566923.png)
3. **Сбросьте службу SSHd на порт 2022 и проверьте в фоновом режиме.**

![1734878836958](image/Readme/1734878836958.png)

`sudo systemctl restart ssh`

![1734879047927](image/Readme/1734879047927.png)

`ps aux | grep sshd`

* **`ps`** — показывает список активных процессов.
* **`aux`** :
* **a** — вывод процессов всех пользователей.
* **u** — отображает информацию о пользователе, запустившем процесс.
* **x** — включает процессы, которые не привязаны к терминалу.
* **`| grep sshd`** — фильтрует вывод команды, показывая только строки, содержащие `sshd`.

4. ·***Вывод команды netstat -tan должен содержать
   tcp 0 0.0.0.0:2022 0.0.0.0:* LISTEN
   (если команды netstat нет, ее необходимо установить);**

`sudo apt install net-tools `

![1734879442338](image/Readme/1734879442338.png)

* **`-t`** : Показывает только TCP-соединения.
* **`-a`** : Показывает все соединения, включая те, которые только слушают.
* **`-n`** : Выводит все адреса и порты в числовом формате, избегая попыток разрешить имена.
* **`tcp`** — тип протокола (TCP).
* **`0`** — количество байт, ожидающих отправки.
* **`0.0.0.0`** — означает, что служба принимает соединения на всех интерфейсах.  Часто используется для  **открытых серверов** , которые должны быть доступны для внешних подключений.
* **`:2022`** — порт, на котором слушает SSHd.
* **`*`** — любые удаленные адреса могут подключиться.
* **`LISTEN`** — порт открыт для входящих подключений.

---

## Task 9 (Установка и использование утилит `top` , `htop`)

1. **Установите и запустите утилиты top и htop.**

##### Top

`sudo apt install htop`

![1734880494867](image/Readme/1734880494867.png)

* **время безотказной работы - `18:14:32 up 20 min`**
* **количество авторизованных пользователей - `1`**
* **средняя загрузка системы - `load average: 0.00, 0.00, 0.00`**
* **общее количество процессов - `93`**
* **загрузка процессора - `%Cpu(s): 0.0 us, 0.3 sy, 0.0 ni, 99.7 id, 0.0 wa, 0.0 hi, 0.0 si, 0.0 st`**
* **загрузка памяти - `MiB Mem :  1971.6 total,  1450.0 free,  142.0 used,  379.6 buff/cache`**
* **pid процесса с наибольшим использованием памяти - `1`**
* **pid процесса, потребляющего больше всего процессорного времени `1313 `**

---

##### Htop

2. **Cортировка по PID, PERCENT_CPU, PERCENT_MEM, TIME** `shift + f6`


![1734881565227](image/Readme/1734881565227.png)

![1734881621143](image/Readme/1734881621143.png)

![1734881675994](image/Readme/1734881675994.png)

![1734881723803](image/Readme/1734881723803.png)

3. **Oтфильтровано для процесса sshd:**
   `f4`

![1734881909243](image/Readme/1734881909243.png)

4. **C процессом syslog, найденным путем поиска:**
   `f3`

![1734882020784](image/Readme/1734882020784.png)

5. **C добавленным выводом имени хоста, часов и времени безотказной работы** :

![1734901432032](image/Readme/1734901432032.png)

---

## Task 10 (Использование утилиты `fdisk`)

1. **Запустите команду fdisk -l.**

```
sudo fdisk -l
```

![1734883790657](image/Readme/1734883790657.png)

* **название жесткого диска** - `/dev/sda`
* **его емкость** - `25 Gib`
* **количество секторов** - `52428800`
* **размер раздела подкачки** - `23Gib`

---

## Task 11 (Использование утилиты `df`)

1. **Выполните команду `df`.**

   ![1734885827331](image/Readme/1734885827331.png)

* **размер раздела** -  `1178760`
* **используемое пространство** - `4923508`
* **cвободное пространство** - `6216144`
* **процент использованного** - `45%`

**Определите и запишите в отчете единицу измерения.** - `килобайты`

2. **Выполните команду `df -Th`.**

   ![1734886045668](image/Readme/1734886045668.png)

* **размер раздела** - `12 G`
* **используемое пространство** - `4.7 G`
* **свободное пространство** - `6.0 G`
* **процент использованного** - `45% `

**Определите и запишите в отчет тип файловой системы раздела.** - `ext4`

---

## Task 12 (Использование утилиты `du`)

**1. Вывести размер папок /home, /var, /var/log (в байтах, в удобном для чтения формате)**

![1734886715352](image/Readme/1734886715352.png)

**2. Вывести размер всего содержимого в /var/log (не общий размер, а каждый вложенный элемент, используя )**

![1734886864074](image/Readme/1734886864074.png)

---

## Task  13 (Установка и использование утилиты `ncdu`)

1. **Установите утилиту ncdu**

![1734887273817](image/Readme/1734887273817.png)

2. **Вывести размер папок /home, /var, /var/log.**

![1734887545894](image/Readme/1734887545894.png)**

---

## Task 14 (**Работа с системными журналами**)

1. **Запишите в отчет время последнего успешного входа в систему, имя пользователя и способ входа.**

   `sudo grep --color=auto "login" /var/log/auth.log 
   `

![1734895224614](image/Readme/1734895224614.png)

**Последний вход 22 декабря 20:37, метод входа login, юзером akhz.**

2. **Перезапустите службу SSHd.**

   `sudo systemctl restart sshd`
3. **Добавьте в отчет снимок экрана сообщения о перезапуске службы (поищите его в журналах).**

   ![1734898640114](image/Readme/1734898640114.png)

---

## Task 15 (CRON)

·1. **Найдите строки в системных журналах (не менее двух в указанном диапазоне времени) о выполнении;**

![1734891754171](image/Readme/1734891754171.png)

![1734890637282](image/Readme/1734890637282.png)

2. **Отображение списка текущих заданий для CRON;**

![1734890643269](image/Readme/1734890643269.png)

3. **Удалите все задачи из планировщика заданий.**

![1734890654556](image/Readme/1734890654556.png)

·
