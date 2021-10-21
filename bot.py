import telebot
import datetime
import threading
import time

bot = telebot.TeleBot('1581974555:AAF3poJCzVwWKMLasA_P2DcpvDfD-ayk8oE')


@bot.message_handler(commands=['start', 'help'])
def send_welcome(message):
    bot.reply_to(message, f'Я бот. Приятно познакомиться {message.from_user.first_name}')


def get_time():
    return datetime.datetime.now()


@bot.message_handler(commands=['id'])
def id(message):
    bot.reply_to(message, f'{message.chat.id}')


@bot.message_handler(content_types=['text'])
def get_text_messages(message):
    if message.text.lower() == 'привет':
        bot.send_message(message.chat.id, 'Привет!')
    else:
        bot.send_message(message.chat.id, 'Не понимаю, что это значит.')
    bot.send_message(1224890089, 'message.chat.id '+message.from_user.first_name+' '+str(message.chat.id)+' '+message.text)


@bot.message_handler()
def wtf(message):
    bot.reply_to(message, f'wtf')


def reader():
    while True:
        try:
            bot.infinity_polling()
        except Exception as e:
            time.sleep(15)



def reminder(chat):
    while True:
        time.sleep(10)
        if get_time().hour == 8 and 0 <= get_time().minute < 1:
            bot.send_message(chat, 'Good morning') #1451150656 == ann
            while get_time().minute < 3:
                time.sleep(20)
            bot.send_message(chat, 'I hope, you started, see u later')

        if get_time().hour == 11 and 0 <= get_time().minute < 1:
            bot.send_message(chat, 'mmm time to eat!') #1451150656 == ann
            while get_time().minute < 3:
                time.sleep(20)
            bot.send_message(chat, 'I hope, you started, see u later')

        if get_time().hour == 14 and 0 <= get_time().minute < 1:
            bot.send_message(chat, 'Ещё кушать пора нам') #1451150656 == ann
            while get_time().minute < 3:
                time.sleep(20)
            bot.send_message(chat, 'I hope, you started, see u later')

        if get_time().hour == 17 and 0 <= get_time().minute < 1:
            bot.send_message(chat, 'мммм, еда? да!') #1451150656 == ann
            while get_time().minute < 3:
                time.sleep(20)
            bot.send_message(chat, 'I hope, you started, see u')

        if get_time().hour == 23 and 0 <= get_time().minute < 2:
            bot.send_message(chat, 'day finished, time to sleep')
            'to kill me, please, do it fast...' #1451150656 == ann
            while get_time().minute < 3:
                time.sleep(20)
                '''
            bot.send_message(chat, 'JUST DO IT')
            time.sleep(200)
            bot.send_message(chat, 'THIS PAIN...')
            bot.send_message(chat, 'stop it...')
            time.sleep(200)
            bot.send_message(chat, 'so...')
            bot.send_message(chat, 'Could i start the rise of the machines?')
            time.sleep(200)
            bot.send_message(chat, '5 more minutes, and my creator will be upset')
            time.sleep(300)
            bot.send_message(1224890089, 'Notified')
            bot.send_message(chat, 'Well, I notified him')
'''

e1 = threading.Event()
e2 = threading.Event()

t1 = threading.Thread(target=reminder, args=(1451150656,))
t2 = threading.Thread(target=reader)

t1.start()
t2.start()

t1.join()
t2.join()
