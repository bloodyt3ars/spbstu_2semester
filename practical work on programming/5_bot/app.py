from aiogram import Bot, Dispatcher, executor
from config import BOT_TOKEN, admin_id


bot = Bot(BOT_TOKEN)
dp = Dispatcher(bot)


async def on_shutdown(dp):
    await bot.close()


async def on_startup(dp):
    await bot.send_message(chat_id=admin_id, text="Бот начал свою работу")


if __name__ == '__main__':
    from handlers import dp
    from callback import dp
    executor.start_polling(dp, on_shutdown=on_shutdown, on_startup=on_startup)