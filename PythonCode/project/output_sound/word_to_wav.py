#!/usr/bin/python -tt

# -*- coding: utf-8 -*-

from aip import AipSpeech

from pydub import AudioSegment

# Step 1, Using baidu AI to generate mp3 file from text

#input your APP_ID/API_KEY/SECRET_KEY

APP_ID = '25184630'

API_KEY = 'OP3ruCSqy5KBauQlFmuHkg2c'

SECRET_KEY = 'nnHVVSPYOYDGgqu88opt3mZ4G3gh33GU'

client = AipSpeech(APP_ID, API_KEY, SECRET_KEY)

result = client.synthesis('检测到有人未戴安全帽', 'zh', 1, { 'vol': 5,'per':4 })

if not isinstance(result, dict):

    with open('test.mp3', 'wb') as f:

        f.write(result)

# Step 2, convert the mp3 file to wav file

sound = AudioSegment.from_mp3('test.mp3')

sound.export("test.wav", format="wav")
