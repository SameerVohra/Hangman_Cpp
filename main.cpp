#include<bits/stdc++.h>
using namespace std;

void printHangman(int wrongGuess){
  switch (wrongGuess) {
    case 0:
            cout << "  +---+\n"
                 << "  |   |\n"
                 << "      |\n"
                 << "      |\n"
                 << "      |\n"
                 << "      |\n"
                 << "=========\n";
            break;
        case 1:
            cout << "  +---+\n"
                 << "  |   |\n"
                 << "  O   |\n"
                 << "      |\n"
                 << "      |\n"
                 << "      |\n"
                 << "=========\n";
            break;
        case 2:
            cout << "  +---+\n"
                 << "  |   |\n"
                 << "  O   |\n"
                 << "  |   |\n"
                 << "      |\n"
                 << "      |\n"
                 << "=========\n";
            break;
        case 3:
            cout << "  +---+\n"
                 << "  |   |\n"
                 << "  O   |\n"
                 << " /|   |\n"
                 << "      |\n"
                 << "      |\n"
                 << "=========\n";
            break;
        case 4:
            cout << "  +---+\n"
                 << "  |   |\n"
                 << "  O   |\n"
                 << " /|\\  |\n"
                 << "      |\n"
                 << "      |\n"
                 << "=========\n";
            break;
        case 5:
            cout << "  +---+\n"
                 << "  |   |\n"
                 << "  O   |\n"
                 << " /|\\  |\n"
                 << " /    |\n"
                 << "      |\n"
                 << "=========\n";
            break;
        case 6:
            cout << "  +---+\n"
                 << "  |   |\n"
                 << "  O   |\n"
                 << " /|\\  |\n"
                 << " / \\  |\n"
                 << "      |\n"
                 << "=========\n";
            break;

    default:
      break;
  }
}

int main(){
  vector<vector<string>> wordsHints = {
        {"apple", "A round object often associated with health"},
        {"elephant", "A large creature known for its long memory"},
        {"guitar", "Something you can strum to create melodies"},
        {"kangaroo", "An animal that carries its young in a pouch"},
        {"volcano", "It sleeps but occasionally has a fiery temper"},
        {"python", "Both a language of logic and a slithery creature"},
        {"airplane", "A machine that conquers the skies"},
        {"library", "A quiet place where knowledge rests on shelves"},
        {"chocolate", "A treat that melts but brings happiness to many"},
        {"pyramid", "A structure built with sharp precision in ancient times"},
        {"basketball", "A game involving a hoop and a bouncing ball"},
        {"diamond", "A precious stone often associated with engagement rings"},
        {"waterfall", "A scenic feature where water cascades down rocks"},
        {"zebra", "An animal with black and white stripes"},
        {"astronaut", "Someone who travels beyond Earth's atmosphere"},
        {"butterfly", "An insect that starts life as a caterpillar"},
        {"jungle", "A dense, wild area full of trees and wildlife"},
        {"clock", "An object that helps you keep track of time"},
        {"rainbow", "A colorful arc that appears after rainfall"},
        {"submarine", "A vessel that travels beneath the surface of the sea"},
        {"mountain", "A large, towering landform, often snow-capped"},
        {"bicycle", "A vehicle with two wheels powered by pedals"},
        {"cactus", "A plant that thrives in deserts and stores water"},
        {"penguin", "A flightless bird that lives in the cold and slides on its belly"},
        {"robot", "A machine that can perform tasks autonomously or semi-autonomously"},
        {"castle", "A large fortified structure often associated with royalty"},
        {"octopus", "A sea creature with eight tentacles and high intelligence"}
  };
  int n = wordsHints.size();

  srand(time(0));
  int randomIdx = rand()%n;

  int wrongGuess = 0;
  int maxGuess = 6;
  string word = wordsHints[randomIdx][0];
  string hint = wordsHints[randomIdx][1];

  vector<char> ans(word.length(), '_');
  vector<bool> check(word.length(), false);
  vector<char> wrongGuessWords;

  while(wrongGuess<maxGuess){
    printHangman(wrongGuess);
    cout << "Wrong Guesses: " ;
    for(char c: wrongGuessWords) cout << c << ", ";
    cout << endl;
    cout << hint << endl;
    for(char c: ans) cout << c << " ";
    cout << endl;

    char guess;
    cin >> guess;

    int idx = 0;
    bool isPresent = false;

    for(int i=0; i<word.length(); i++){
      if(word[i]==guess && !check[i]){
        check[i] = true;
        isPresent = true;
        ans[i] = guess;
        break;
      }
    }

    if(!isPresent){
      wrongGuessWords.push_back(guess);
      wrongGuess++;
    }
    
    bool isGuessCorrect = true;

    for(bool i: check){
      if(i==false){
        isGuessCorrect = false;
        break;
      }
    }

    if(isGuessCorrect){
      for(char c: ans) cout << c << " ";
      cout << endl;
      cout << "You Won!!" << endl;
      break;
    }
    if(wrongGuess==maxGuess){
      printHangman(wrongGuess);
      cout << "Word Was: " << word << endl;
      cout << "You Lose!!" << endl;
      break;
    }
  }
}
