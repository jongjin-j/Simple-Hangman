var c = document.getElementById("myCanvas");
var ctx = c.getContext("2d");
var failCount = 0;
var alphabetCount = 0;
var usedAlphabets = [];
var word = "apple";
var wordSplit = word.split('');
var currentArray = [];
var proceed = false;
usedAlphabets.length = 26;
currentArray.length = word.length;

for(var i = 0; i < currentArray.length; i++){
    currentArray[i] = " _";
}

for(var i = 0; i < usedAlphabets.length; i++){
    usedAlphabets[i] = null;
}

document.addEventListener("keydown", keyDownControl, false);

printBlanks(word);

function keyDownControl(k){
    if(k.key == "Right" || "ArrowRight"){
        if(checkEndOfGame(failCount) == true){
            alert("GAME OVER BYE");
            document.location.reload();
        }
        var userInput = prompt("Guess an alphabet", "<Enter here>");

        //the bottom half in a function

        if(userInput != null){
            //print usedAlphabets
            //print currentArray
            //function to wait for next prompt *****
        
            var inputLength = userInput.length;
            
            if(inputLength > 1){
                document.getElementById("output").innerHTML = "too long - input should be a length of 1";
            }
            else if(inputLength < 1){
                document.getElementById("output").innerHTML = "too short - input should be a length of 1";
            }
            else{
                if(checkIfAlphabet(userInput) == false){
                    document.getElementById("output").innerHTML = "invalid input - enter an alphabet";
                }
                else{
                    if(alphabetUsed(userInput, usedAlphabets) == true){
                        document.getElementById("output").innerHTML = "input already used, enter a different alphabet";
                    }
                    else{
                        if(checkMatch(userInput) == true){
                            usedAlphabets[alphabetCount] = userInput;
                            document.getElementById("output").innerHTML = "Alphabet: '" + userInput + "' is in the word.";
                            updateCurrentArray(userInput, currentArray, wordSplit);
                            draw(failCount);
                            alphabetCount++;
                            printUsedAlphabets(usedAlphabets, alphabetCount);
                            printCurrentArray(currentArray, currentArray.length);
                        }
                        else{
                            usedAlphabets[alphabetCount] = userInput;
                            document.getElementById("output").innerHTML = "Alphabet: '" + userInput + "' does not match the word";
                            failCount++;
                            draw(failCount);
                            alphabetCount++;
                            printUsedAlphabets(usedAlphabets, alphabetCount);
                            printCurrentArray(currentArray, currentArray.length);
                        }
                    }
                }
            }
       }
    }
}

function checkEndOfGame(failCount){
    if(failCount == 10){
        return true;
    }
    return false;
}

function checkIfAlphabet(c){
    return c.toLowerCase() != c.toUpperCase();
}

function alphabetUsed(c){
    for(var i = 0; i < usedAlphabets.length; i++){
        if(usedAlphabets[i] == c){
            return true;
        }
    }
    return false;
}

function checkMatch(c){
    for(var i = 0; i < wordSplit.length; i++){
        if(wordSplit[i] == c){
            return true;
        }
    }
    return false;
}

function printBlanks(w){
    var wordLength = w.length;
    for(var i = 0; i < wordLength; i++){
        document.getElementById("output_1").innerHTML = "_ _ _ _ _";
    }
}

function updateCurrentArray(c, current, word){
    for(var i = 0; i < word.length; i++){
        if(c == word[i]){
            current[i] = c;
        }
    }
}

function printUsedAlphabets(alphabetArray, count){
    var result = "Used Alphabets: ";
    for(var i = 0; i < count; i++){
        result += alphabetArray[i] + " ";
    }
    document.getElementById("output_2").innerHTML = result;
}

function printCurrentArray(current, wordLength){
    var result = "";
    for(var i = 0; i < wordLength; i++){
        result += current[i] + " ";
    }
    document.getElementById("output_1").innerHTML = result;
}



function draw(n){
    if(n == 1){
        ctx.beginPath();
        ctx.moveTo(140, 550);
        ctx.lineTo(360, 550);
        ctx.stroke();
        ctx.closePath();
    }
        
    if(n == 2){
        draw(1);
        ctx.beginPath();
        ctx.moveTo(250, 550);
        ctx.lineTo(250, 150);
        ctx.stroke();
        ctx.closePath();
    }
        
    if(n == 3){
        draw(2);
        ctx.beginPath();
        ctx.moveTo(250, 150);
        ctx.lineTo(410, 150);
        ctx.stroke();
        ctx.closePath();
    }
        
    if(n == 4){
        draw(3);
        ctx.beginPath();
        ctx.moveTo(410, 150);
        ctx.lineTo(410, 200);
        ctx.stroke();
        ctx.closePath();
    }

    if(n == 5){
        draw(4);
        ctx.beginPath();
        ctx.arc(410, 225, 25, 0, 2 * Math.PI);
        ctx.stroke();
        ctx.closePath();
    }
        
    if(n == 6){
        draw(5);
        ctx.beginPath();
        ctx.moveTo(410, 250);
        ctx.lineTo(410, 400);
        ctx.stroke();
        ctx.closePath();
    }
    
    if(n == 7){
        draw(6);
        ctx.beginPath();
        ctx.moveTo(410, 300);
        ctx.lineTo(360, 350);
        ctx.stroke();
        ctx.closePath();
        }                       
    
    if(n == 8){
        draw(7);
        ctx.beginPath();
        ctx.moveTo(410, 300);
        ctx.lineTo(460, 350);
        ctx.stroke();
        ctx.closePath();
    }
        
    if(n == 9){
        draw(8);
        ctx.beginPath();
        ctx.moveTo(410, 400);
        ctx.lineTo(360, 450);
        ctx.stroke();
        ctx.closePath();
    }
        
    if(n == 10){
        draw(9);
        ctx.beginPath();
        ctx.moveTo(410, 400);
        ctx.lineTo(460, 450);
        ctx.stroke();
        drawEyes();
        drawTongue();  
    }
}

function drawEyes(){
    ctx.beginPath();
    ctx.moveTo(395, 215);
    ctx.lineTo(400, 220);
    ctx.moveTo(395, 220);
    ctx.lineTo(400, 215);
    ctx.moveTo(420, 215);
    ctx.lineTo(425, 220);
    ctx.moveTo(420, 220);
    ctx.lineTo(425, 215);
    ctx.stroke();
    ctx.closePath();
}

function drawTongue(){
    ctx.beginPath();
    ctx.moveTo(405, 230);
    ctx.lineTo(415, 230);
    ctx.moveTo(410, 230);
    ctx.lineTo(410, 245);
    ctx.moveTo(405, 230);
    ctx.bezierCurveTo(405, 250, 415, 250, 415, 230);
    ctx.strokeStyle = "red";
    ctx.stroke();
    ctx.closePath();
}