from asyncio import sleep
import requests
import json
from aiogram.types import Message, ChatActions
from app import bot, dp
from keyboard import menu
from config import WEATHER_TOKEN


@dp.message_handler(commands=['start'])
async def process_start_command(message: Message):
    await message.answer("Привет. Тут можно узнать прогноз погоды в интересующем тебя городе.",
                         reply_markup=menu)


@dp.message_handler(commands=["menu"])
async def send_menu(message: Message):
    await bot.send_chat_action(message.from_user.id, ChatActions.TYPING)
    await sleep(1)
    await message.answer(text="Основное меню", reply_markup=menu)


@dp.message_handler()
async def get_weather(message: Message):
    await bot.send_chat_action(message.from_user.id, ChatActions.TYPING)
    await sleep(1)
    city = message.text
    weather_request = f'http://api.openweathermap.org/data/2.5/weather?q={city}&appid={WEATHER_TOKEN}'
    response = requests.get(weather_request)
    if response.status_code != 200:
        await message.answer(text="Упс...Город не найден")
    data = json.loads(response.content)
    for elem in data['weather']:
        weather_state = elem['main']
    temperature = data['main']['temp'] - 273.15
    temperature = round(temperature, 1)
    city = data['name']
    await message.answer(text=f"Температура в {city}: {temperature}, {weather_state}")
