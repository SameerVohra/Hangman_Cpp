# Hangman

A command-line word guessing game where players try to guess a word based on cryptic hints. The game is built in C++ and follows the classic Hangman rules with an added twist of short, challenging hints for each word.

## Table of Contents

- [Features](#features)
- [Game Play](#game-play)
- [Setup](#setup)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Features

- **Short, Cryptic Hints**: The game provides minimal, abstract clues to challenge the player.
- **Classic Hangman Gameplay**: Players guess the word one letter at a time, with a limited number of incorrect guesses allowed before the game is lost.
- **Wide Range of Words**: The word list includes a variety of categories like animals, objects, food, and more.

## Game Play

The game presents a hidden word with underscores representing each letter. A short hint is given for each word. The player must guess one letter at a time, and for each incorrect guess, a part of the hangman figure is drawn.

Example:
```
Hint: "Sky traveler"
Word: _ _ _ _ _ _ _ _
Guess a letter: a
Correct!
Word: _ a _ _ _ _ a _ _
```

If the player guesses the word before the hangman is fully drawn, they win! Otherwise, the game ends when the hangman is complete.

## Setup

### Prerequisites

- A C++ compiler (such as GCC or Clang).

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/SameerVohra/Hangman_Cpp.git   
   ```

2. Navigate to the project directory:
   ```bash
   cd hangman
   ```

3. Compile the game:
   ```bash
   g++ main.cpp
   ```

4. Run the game:
   ```bash
   ./a.out
   ```

## Usage

Once the game starts, you will be shown a hint and an empty word where each letter is represented by an underscore (`_`). You need to guess the letters one by one. You have a limited number of incorrect guesses before the hangman is fully drawn.

### Example Game Flow

```
Hint: "Ocean giant"
Word: _ _ _ _ _ _
Guess a letter: w
Incorrect! You have 5 incorrect guesses left.

Guess a letter: h
Correct!
Word: _ h _ _ _ _
```

The game continues until you guess the word or run out of incorrect guesses.
