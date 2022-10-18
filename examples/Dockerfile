FROM python:3.10
RUN python -m pip install --upgrade pip && pip install numpy tensorflow gin-config scikit-build hanabi-learning-environment
WORKDIR /app

CMD [ "python3", "game_example.py" ]