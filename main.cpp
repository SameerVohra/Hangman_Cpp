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
      {"apple", "Keeps someone away."},
      {"elephant", "Big memory."},
      {"guitar", "Strums and tunes."},
      {"kangaroo", "Leaps with a pouch."},
      {"volcano", "Dormant yet fiery."},
      {"python", "Slithers or codes."},
      {"airplane", "Sky traveler."},
      {"library", "Silent shelves."},
      {"chocolate", "Melts happiness."},
      {"pyramid", "Ancient geometry."},
      {"basketball", "Hoop and bounce."},
      {"diamond", "Shines under pressure."},
      {"waterfall", "Falling flow."},
      {"zebra", "Striped runner."},
      {"astronaut", "Beyond Earth."},
      {"butterfly", "Wings after crawling."},
      {"jungle", "Wild and dense."},
      {"clock", "Ticks time."},
      {"rainbow", "Colors after rain."},
      {"submarine", "Underwater explorer."},
      {"mountain", "Towering peak."},
      {"bicycle", "Two wheels, pedals."},
      {"cactus", "Desert survivor."},
      {"penguin", "Cold, flightless slide."},
      {"robot", "Automated helper."},
      {"castle", "Fortified royalty."},
      {"octopus", "Eight-limbed intelligence."},
      {"fireworks", "Colorful explosions."},
      {"mosquito", "Buzzing biter."},
      {"backpack", "Carried storage."},
      {"balloon", "Air-filled floater."},
      {"keyboard", "Typed input."},
      {"telescope", "Distant viewer."},
      {"cricket", "Bat and ball."},
      {"whale", "Ocean giant."},
      {"spaghetti", "Twisted meal."},
      {"dragon", "Mythical fire-breather."},
      {"seashell", "Ocean's souvenir."},
      {"umbrella", "Rain protector."},
      {"volleyball", "Net sport."},
      {"magnet", "Attracts metal."},
      {"rocket", "Skyward vehicle."},
      {"donut", "Sweet circle."},
      {"peacock", "Colorful feathers."},
      {"microscope", "Tiny viewer."},
      {"glacier", "Frozen mover."},
      {"dolphin", "Intelligent swimmer."},
      {"sandcastle", "Beach structure."},
      {"jellyfish", "Tentacled floater."},
      {"candle", "Burning light."},
      {"skeleton", "Internal structure."},
      {"compass", "Direction guide."},
      {"snowflake", "Unique ice crystal."},
      {"caterpillar", "Future butterfly."},
      {"boomerang", "Returning throw."},
      {"hotdog", "Grilled snack."},
      {"sunflower", "Follows light."},
      {"watermelon", "Summer fruit."},
      {"sailboat", "Wind-powered vessel."},
      {"headphones", "Private sound."},
      {"snowman", "Frosty figure."},
      {"honeybee", "Sweet maker."},
      {"newspaper", "Printed news."},
      {"lighthouse", "Coastal guide."},
      {"basket", "Woven holder."},
      {"tornado", "Spinning storm."},
      {"violin", "String instrument."},
      {"skateboard", "Street rider."},
      {"octagon", "Eight sides."},
      {"avocado", "Green, creamy fruit."},
      {"flashlight", "Portable light."},
      {"parachute", "Controlled descent."},
      {"cheeseburger", "Savory stack."},
      {"hedgehog", "Spiny creature."},
      {"chess", "Strategic board."},
      {"koala", "Eucalyptus eater."},
      {"anchor", "Stabilizing weight."},
      {"piano", "Keys and notes."},
      {"helicopter", "Rotor flyer."},
      {"tiger", "Striped predator."},
      {"strawberry", "Seeded red."},
      {"binoculars", "Distance enhancer."},
      {"safari", "Wildlife journey."},
      {"bottle", "Liquid container."},
      {"eraser", "Pencil undoer."},
      {"typewriter", "Old-school typing."},
      {"igloo", "Icy shelter."},
      {"spider", "Web weaver."},
      {"trampoline", "Jumping fun."},
      {"lantern", "Portable glow."},
      {"origami", "Paper artistry."},
      {"crocodile", "River predator."},
      {"xylophone", "Bar instrument."},
      {"laptop", "Portable computer."}
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
