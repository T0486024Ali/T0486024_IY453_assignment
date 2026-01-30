# IY453 Stage 1

| Assessment Details | Please Complete All Details               |
| ------------------ | ----------------------------------------- |
| Group              | B.                                        |
| Module Title       | IY453 Software Design and Implementation. |
| Assessment Type    | Coursework.                               |
| Module Tutor Name  | Shore Jonathan.                           |
| Student ID Number  | T0486024                                  |
| Date of Submission | 30/1/2026                                 |
| Word Count         |                                           |

- [x] *I confirm that this assignment is my own work. Where I have referred to academic sources, I have provided in-text citations and included the sources in
  the final reference list.*

- [x] *Where I have used AI, I have cited and referenced appropriately.

------------------------------------------------------------------------------------------------------------------------------

### The program purpose

The program's purpose is to design a text-based adventure game that allows players to have more interaction by relocating them to a fictional world to help them solve problems and make decisions. This game relies on descriptive writing and user input.

This game has functional and non-functional requirements. The functional requirements are like player interaction, engagement, and error handling. The non-functional requirements of the game are like code quality, user experience, testing, debugging, and documentation.

The game uses at least 30 binary choices in each scenario to meet the functional requirements. Some choices lead to a "Game Over" state, while others allow progress. Additionally, the game has to provide clear feedback for its choices.

### The IPO (input, process, and output table)

| **Feature / Task**  | **Input**                          | **Process**                                   | **Output**                                  |
| ------------------- | ---------------------------------- | --------------------------------------------- | ------------------------------------------- |
| Start game          | Player name (string)               | Store name in Player object                   | Personalized welcome message                |
| Main menu selection | Menu choice (New Game / Load Game) | Validate choice and branch program flow       | Game starts or saved game loads             |
| Scene navigation    | Binary choice (1 or 2)             | Validate input and determine next scene       | New scenario description                    |
| Risk-based decision | Binary choice                      | Apply consequences based on choice            | Health change, item gain/loss, or Game Over |
| Puzzle challenge    | Puzzle answer (string or number)   | Compare input with correct solution           | Puzzle success or failure message           |
| Puzzle reward       | Correct puzzle answer              | Increase score and unlock next scene          | Score update and progression                |
| Puzzle penalty      | Incorrect puzzle answer            | Reduce health or end game                     | Damage message or Game Over                 |
| Combat initiation   | Fight / Run choice                 | Determine combat or escape logic              | Combat start or retreat message             |
| Combat resolution   | Random number (system)             | Add random value to combat ratings            | Win or lose combat outcome                  |
| Enemy defeated      | Combat win                         | Update score and possibly drop item           | Victory message and score increase          |
| Item discovery      | Pick up item (Yes / No)            | Add item to inventory if space allows         | Item added confirmation                     |
| Inventory viewing   | Inventory command                  | Retrieve stored inventory items               | Display list of collected items             |
| Item usage          | Selected inventory item            | Modify player stats (health, attack, defense) | Updated stats displayed                     |
| Food or potion use  | Item selection                     | Restore health or boost stats                 | Health restored message                     |
| Equipment handling  | Weapon or armor selection          | Apply stat bonuses                            | Increased attack or defense                 |
| Locked path access  | Use key item                       | Check inventory for key                       | Door opens or access denied                 |
| Save game           | Save command                       | Serialize player data to file                 | Save success or error message               |
| Save file naming    | File name (text)                   | Create or overwrite save file                 | Confirmation message                        |
| Load game           | Load command                       | Read game state from file                     | Game state restored                         |
| Player defeat       | Health reaches zero                | Trigger game-over logic                       | Game Over screen                            |
| Game completion     | Final victory condition            | Calculate final score                         | Victory message and final score             |

Full reference for this AI tool:
ChatGPT. (2026). An IPO table for this text-based adventure game. OpenAI.

prompt: Please give me an IPO table for this text-based adventure game.

### Algorithm design

Flowchart:

(ChatGPT, 2026)

![](C:\Users\alimt\Downloads\ChatGPT%20Image%20Jan%2030,%202026,%2011_54_47%20AM.png)

Full reference for this AI tool:
ChatGPT. (2026). A flowchart for this text-based adventure game. OpenAI.

prompt: Please give me a flowchart for this text-based adventure game.

Class diagram:

(ChatGPT, 2026)

![](C:\Users\alimt\Downloads\ChatGPT%20Image%20Jan%2030,%202026,%2011_55_34%20AM.png)



Full reference for this AI tool:
ChatGPT. (2026). A class diagrasm for this text-based adventure game. OpenAI.

prompt: Please give me a class diagram for this text-based adventure game.
