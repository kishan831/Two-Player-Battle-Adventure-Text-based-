#include <iostream>
using namespace std;

//Player We Are Using In The Game
enum PlayerType {
  PubgPlayer,
  EnemyPlayer,
  ZombiePlayer,
};

// Interface for Player classes
class BasePlayer {

protected:           //Used For Every Child Classes Can Use It.
  int PlayerHealth;
  int PlayerDamage;
  int AdditionalDamage;
  int HealingCapacity;
  int MaxHealth;
  PlayerType player;

//Using Setter And Getter For Every Player
public:
  virtual PlayerType const GetPlayerType() = 0;
  virtual int const GetPlayerHealth() = 0;
  virtual void SetPlayerHealth(int value) = 0;
  virtual int const GetPlayerDamage() = 0;
  virtual void SetPlayerDamage(int value) = 0;
  virtual int const GetAdditionalDamage() = 0;
  virtual void SetAdditionalDamage(int value) = 0;
  virtual int const GetHealingCapacity() = 0;
  virtual void SetHealingCapacity(int value) = 0;
  virtual int const GetMaxHealth() = 0;

  virtual void TakeDamage(int damage) = 0;
  virtual void HealPlayer(int health) = 0;
  virtual int const GetTotalDamage() = 0;

  virtual void RandomizeAdditionalDamage() = 0;
  virtual void RandomizeHealingCapacity() = 0;

  virtual void ApplyDamage(BasePlayer *otherPlayer) = 0;
  virtual void ApplyHealing(BasePlayer *otherPlayer) = 0;
  virtual void MaximumHealthCheck() = 0;

  virtual ~BasePlayer() = 0;
};

BasePlayer:: ~BasePlayer(){}  //

// Implementation of Interface Base for different player class
class Player : public BasePlayer {
public:
  Player(int PlayerHealth, int PlayerDamage, int AdditionalDamage, int HealingCapacity, PlayerType Player) {

    this->PlayerHealth = PlayerHealth;
    this->PlayerDamage = PlayerDamage;
    this->AdditionalDamage = AdditionalDamage;
    this->HealingCapacity = HealingCapacity;
    this->MaxHealth = PlayerHealth;
    this->player = Player;
  }

  PlayerType const GetPlayerType() {
    return player;
  }

  int const GetPlayerHealth() {
    return PlayerHealth;
  }

  void SetPlayerHealth(int value) {
    PlayerHealth = value;
  }

  int const GetPlayerDamage() {
    return PlayerDamage;
  }

  void SetPlayerDamage(int value) {
    PlayerDamage = value;
  }

  int const GetAdditionalDamage() {
    return AdditionalDamage;
  }

  void SetAdditionalDamage(int value) {
    AdditionalDamage = value;
  }

  int const GetHealingCapacity() {
    return HealingCapacity;
  }

  void SetHealingCapacity(int value) {
    HealingCapacity =  value;
  }

  int const GetMaxHealth() {
    return MaxHealth;
  }

  void TakeDamage(int damage)  {
    PlayerHealth -= damage;
  }

  void HealPlayer(int health) {
    PlayerHealth += health;
  }

  int const GetTotalDamage() {
    return PlayerDamage + AdditionalDamage;
  }

  virtual void RandomizeAdditionalDamage() {
    SetAdditionalDamage(5 + (rand() % 10));
  }

  virtual void RandomizeHealingCapacity() {
    SetHealingCapacity(5 + (rand() % 5));
  }

  void ApplyDamage(BasePlayer *otherPlayer);
  void ApplyHealing(BasePlayer *otherPlayer);
  void MaximumHealthCheck();
};

// Creating player types by inheriting properties from player class 
class Pubg1Player : public Player {
public:
  Pubg1Player(int PlayerHealth, int PlayerDamage, int AdditionalDamage, int HealingCapacity) : Player(PlayerHealth, PlayerDamage, AdditionalDamage, HealingCapacity, PlayerType::PubgPlayer){}

  void RandomizeAdditionalDamage() {             //Random Damage And Healing For Pubg1Player
    SetAdditionalDamage(4 + (rand() % 10));
  }

  void RandomizeHealingCapacity() {
    SetHealingCapacity(5 + (rand() % 5));
  }

};

class Enemy1Player : public Player {
public:
  Enemy1Player(int PlayerHealth, int PlayerDamage, int AdditionalDamage, int HealingCapacity) : Player(PlayerHealth, PlayerDamage, AdditionalDamage, HealingCapacity, PlayerType::EnemyPlayer) {}

  void RandomizeAdditionalDamage() {              //Random Damage And Healing For Enemy1Player
    SetAdditionalDamage(6 + (rand() % 10));
  }

  void RandomizeHealingCapacity() {
    SetHealingCapacity(10 + (rand() % 10));
  }

};

class Zombie1Player : public Player {
public:
  Zombie1Player(int PlayerHealth, int PlayerDamage, int AdditionalDamage, int HealingCapacity) : Player(PlayerHealth, PlayerDamage, AdditionalDamage, HealingCapacity, PlayerType::ZombiePlayer) {}

  void RandomizeAdditionalDamage() {               //Random Damage And Healing For Zombie1Player
    SetAdditionalDamage(8 + (rand() % 10));
  }

  void RandomizeHealingCapacity() {
    SetHealingCapacity(15 + (rand() % 10));
  }
};

//Instructions Of The Battle-Adventure Game
void ShowGameInstruction() {
  cout << endl << endl;
  cout << "!! Welcome To 2-Player-Battle-Adventure Game !!" << endl << endl<< endl;

  cout << "Instructions :" << endl;
  cout << "1) Each player has one choice at a time." << endl;
  cout << "2) The player can either attack or heal." << endl;
  cout << "3) The player who's health goes below 0, will die and loose the game." << endl;
  cout << "4) Press 'H' to heal and 'A' to attack." << endl;
  cout << "5) Each special ability has 20% probability." << endl << endl << endl;

  cout << "Game Player types " << endl;
  cout << "***************** " << endl << endl;

  cout << "1) Pubg Player     - High Health, Low Heal, Low Base Damage, Low Additional Damage" << endl;
  cout << "   Special Ability - Huge Heal" << endl;
  cout << "                   - Double Attack" << endl << endl;

  cout << "2) Enemy Player    - Average Health, High Heal, Average Base Damage, Average Additional Damage" << endl;
  cout << "   Special Ability - Attack Blocker" << endl;
  cout << "                   - Heal + Damage in single turn" << endl << endl;

  cout << "3) Zombie Player   - Low Health, Very High Heal, High Base Damage, High Additional Damage" << endl;
  cout << "   Special Ability - Rage (Damage increases when close to death)" << endl;
  cout << "                   - Critical Hit" << endl;

  cout << endl << endl;
} 


//Intitial Stats Of Players
void ShowInitialStats(BasePlayer* player, int index) {
  switch(index) {
    case 1:
      cout << "Pubg Player - Whatever Tt Takes !" << endl;
      break;
    case 2:
      cout << "Enemy Player - Ready For All !" << endl;
      break;
    case 3:
      cout << "Zombie Player - Conqurers Of All !" << endl;
      break;
  }

  cout << "Player health : " << player->GetPlayerHealth() << endl;
  cout << "Base Damage : " << player->GetPlayerDamage() << endl;

  switch(index) {
    case 1:
      cout << "Additional Damage : 4 - 14" << endl;
      cout << "Healing Capacity : 5 - 10" << endl << endl;
      break;
    case 2:
      cout << "Additional Damage : 6 - 16" << endl;
      cout << "Healing Capacity : 10 - 20" << endl << endl;
      break;
    case 3:
      cout << "Additional Damage : 8 - 18" << endl;
      cout << "Healing Capacity : 20 - 30" << endl << endl;
      break;
  }
}

//Health Of Two Player Who Will Fight
void ShowPlayerStats(BasePlayer* player1, BasePlayer* player2) {
  cout << "Player 1 : Health = " << player1->GetPlayerHealth() << endl;
  cout << "Player 2 : Health = " << player2->GetPlayerHealth() << endl << endl << endl;
}


//Creation Of Players 
BasePlayer* CreatePlayerOfType(int value) {

  switch(value) {
    case 1: {
        BasePlayer* powerPlayer = new Pubg1Player(200, 10, 0, 0);
        ShowInitialStats(powerPlayer, 1);
        return powerPlayer;
      }
      break;
  
    case 2: {
        BasePlayer* skilledPlayer = new Enemy1Player(150, 20, 0, 0);
        ShowInitialStats(skilledPlayer, 2);
        return skilledPlayer;
      }
      break;

    case 3: {
        BasePlayer* ragedPlayer = new Zombie1Player(100, 30, 10, 0);
        ShowInitialStats(ragedPlayer, 3);
        return ragedPlayer;
      }
      break;

    Default:
    return nullptr;
    break;
  } 
  return nullptr;
}


//Player Selection From User
BasePlayer* SelectPlayerType(int value) {
  int playerChoice = 0;

  cout << endl;
  cout << "Player " << value << " : Select player type (1, 2, 3)" << endl;
  cout << "Player Type : " ;

  while(true) {
    cin >> playerChoice;
    cout << endl ;

    if(!cin || !(playerChoice == 1 || playerChoice == 2 || playerChoice == 3)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');  //Used For Not Take Input Up to 3.

      cout << "Please select correct player type" << endl;
      cout << "Player Type : " ;
      continue;
    }
    else  {     
      break;
    }
  }
  return CreatePlayerOfType(playerChoice);  
}


//Applying Action Of Players Taking Input From User
void ActionCalling(BasePlayer* player1, BasePlayer* player2) {
  char playerAction;

  cin >> playerAction;

  if(playerAction == 'a' || playerAction == 'A') {

        player2->ApplyDamage(player1);
      }

  else if(playerAction == 'h' || playerAction == 'H') {

    if(!(player1->GetPlayerHealth() >= player1->GetMaxHealth())) {

      player1->ApplyHealing(player2);
      cout << "Total heal = " << player1->GetHealingCapacity() << endl;
    }
    else {
      cout << "Your health is full. Try Take Some Damage Yourself From Enemy." << endl;
    }   
  }
}

//Battle Begin With Two Player
void BattleBegin(BasePlayer* player1, BasePlayer* player2) {
  int playerAction = 1;

  cout << "! Battle Started !" << endl;

  while(true) {

    if(player1->GetPlayerHealth() <= 0) {
      cout << "!! Player 2 won !!" << endl << endl;
      break;
    }
    else if(player2->GetPlayerHealth() <= 0) {
      cout << "!! Player 1 won !!" << endl << endl;
      break;
    }

    cout << "Player " << playerAction << " : Enter 'A' To Attack or 'H' To Heal " << endl;
    cout << "Player " << playerAction << " : ";

    if(playerAction == 1) {
      ActionCalling(player1, player2);
      ShowPlayerStats(player1, player2);
      playerAction++;
    }

    else {   
      ActionCalling(player2, player1);
      ShowPlayerStats(player1, player2);
      playerAction--;
    }    
  }

}

//Apply Damage On otherPlayer And Apply Some Special Abilities Of Every Player ( We Have Given In The Program ) 
void Player::ApplyDamage(BasePlayer *otherPlayer) {
  otherPlayer->RandomizeAdditionalDamage();   // To Randomize Additional Damage

  switch(otherPlayer->GetPlayerType()) {

    case PubgPlayer:
      if( (GetPlayerType() == EnemyPlayer) && (rand() % 4 == 0)) {
        cout << "Special Ability Used By Opponent - Attack Blocker" << endl;
        cout << "Damage given = 0" << endl;
        break;
      }

      if(rand() % 4 == 0) {
        otherPlayer->SetAdditionalDamage( 2 * otherPlayer->GetAdditionalDamage());
        otherPlayer->SetPlayerDamage( 2 * otherPlayer->GetPlayerDamage());
        TakeDamage(otherPlayer->GetTotalDamage());

        cout << "Special Ability Used - Double Attack" << endl;
        cout << "Damage given = " << otherPlayer->GetTotalDamage() << endl;

        otherPlayer->SetPlayerDamage(otherPlayer->GetPlayerDamage() / 2);
        break;
      }
      else {
        TakeDamage(otherPlayer->GetTotalDamage());
        cout << "Damage given = " << otherPlayer->GetTotalDamage() << endl;
      }
      break;

    case EnemyPlayer:
      if(rand() % 4 == 0) {
        cout << "Special Ability Used - Heal + Damage" << endl;

        otherPlayer->ApplyHealing(otherPlayer);
        TakeDamage(otherPlayer->GetTotalDamage());

        cout << "Damage given = " << otherPlayer->GetTotalDamage() << endl;
        cout << "Total heal = " << otherPlayer->GetHealingCapacity() << endl;
      }

      else {
        TakeDamage(otherPlayer->GetTotalDamage());
        cout << "Damage given = " << otherPlayer->GetTotalDamage() << endl;
      }
      break;


    case ZombiePlayer:
      if( (GetPlayerType() == EnemyPlayer) && (rand() % 4 == 0)) {
        cout << "Special Ability Used By Opponent - Attack Blocker" << endl;
        cout << "Damage given = 0" << endl;
        break;
      }

      if( (GetPlayerHealth() <= 0.3 * GetMaxHealth())) {
        otherPlayer->SetPlayerDamage( (otherPlayer->GetPlayerDamage() + 100/(otherPlayer->GetPlayerHealth())) );
        cout << "Special Ability Used - Rage" << endl;

          if((rand() % 4 == 0)) {
            otherPlayer->SetAdditionalDamage( 1.5 * otherPlayer->GetAdditionalDamage());
            otherPlayer->SetPlayerDamage( 1.5 * otherPlayer->GetPlayerDamage());
            TakeDamage(otherPlayer->GetTotalDamage());

            cout << "Special Ability Used - Critical Hit" << endl;
            cout << "Damage given = " << otherPlayer->GetTotalDamage() << endl;

            otherPlayer->SetPlayerDamage(otherPlayer-> GetPlayerDamage() / 2);
            break;
          }

          else {
            TakeDamage(otherPlayer->GetTotalDamage());
            cout << "Damage given = " << otherPlayer->GetTotalDamage() << endl;
          }   
      }

      else {
        TakeDamage(otherPlayer->GetTotalDamage());
        cout << "Damage given = " << otherPlayer->GetTotalDamage() << endl;
      }
      break;
  }

  if(GetPlayerHealth() <= 0)
  {
    SetPlayerHealth(0);
  }
}


//Apply Healing For Players
void Player::ApplyHealing(BasePlayer* otherPlayer) {

  RandomizeHealingCapacity(); // To randomize healing capacity

  switch(GetPlayerType()) {

    case PubgPlayer:
      if(rand() % 4 == 0) {

        cout << "Special Ability Used - Huge Heal" << endl;
        SetHealingCapacity(2 * GetHealingCapacity());
        MaximumHealthCheck();
      }
      else {
        MaximumHealthCheck();
      }
      break;

    case EnemyPlayer:
      MaximumHealthCheck();
      break;

    case ZombiePlayer:
      MaximumHealthCheck();
      break;
  } 
}


//For Checking Health Of Players Must Not Exceed From Given Values
void Player::MaximumHealthCheck() {
  if(GetPlayerHealth() + GetHealingCapacity() > GetMaxHealth()) { 
      SetHealingCapacity(GetMaxHealth() - GetPlayerHealth());
      SetPlayerHealth(GetPlayerHealth() + GetHealingCapacity());
    }
    else {
      SetPlayerHealth(GetPlayerHealth() + GetHealingCapacity());
    }  
}

int main() {

  char restart; // Used Restarting Of Game  

  while(true) {
    ShowGameInstruction();

    BasePlayer* player1 = SelectPlayerType(1);
    BasePlayer* player2 = SelectPlayerType(2);

    BattleBegin(player1, player2);

    delete player1;
    delete player2;

    cout << "Press 'E' To Play Again" << endl;
    cin >> restart;

    if(!(restart == 'e' || restart == 'E')) {
      cout << "I Will Try To Improvise This Game For You See You Next Time !" << endl;
      break;
    }
  }
  return 0;
}