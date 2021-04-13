from asyncio import sleep

from aiogram.types import CallbackQuery, ChatActions

from app import dp, bot
from keyboard import menu


@dp.callback_query_handler(text="location")
async def process_info_command(call: CallbackQuery):
    await bot.send_chat_action(call.from_user.id, ChatActions.TYPING)
    await sleep(1)
    await call.message.answer(text="Напиши интересующий тебя город.",
                              reply_markup=None)


@dp.callback_query_handler(text="info")
async def process_help_command(call: CallbackQuery):
    await bot.send_chat_action(call.from_user.id, ChatActions.TYPING)
    await sleep(1)
    await call.message.answer(text="Привет. Тут можно узнать прогноз погоды в интересующем тебя городе.,"
                                   "\nЭту работу выполнили студенты полиКЕКа Алиса, Вова, Алиса и Ксюша.",
                              reply_markup=menu)


@dp.callback_query_handler(text="cancel")
async def cancel_command(call: CallbackQuery):
    await call.answer("Для того, что бы заново открыть меню, пропиши /menu", show_alert=True)
    await call.message.edit_reply_markup(reply_markup=None)
