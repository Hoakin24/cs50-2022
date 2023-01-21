let redBallEl = document.getElementById("red-ball-count-el");
let blueBallEl = document.getElementById("blue-ball-count-el");
let yellowBallEl = document.getElementById("yellow-ball-count-el");
let randomBallEl = document.getElementById("random-ball-el");

let randomBallBtn = document.getElementById("random-ball-btn");
let addRedBtn = document.getElementById("add-red-btn");
let addBlueBtn = document.getElementById("add-blue-btn");
let addYellowBtn = document.getElementById("add-yellow-btn");

let coloredBalls = ["🔴", "🔵", "🟡", "🔴", "🔵", "🟡"];
let redBalls;
let blueBalls;
let yellowBalls;

function countBalls()
{
    for (i = 0; i < coloredBalls.length; i++)
    {
        if (coloredBalls[i] === "🔴" || coloredBalls.includes("🔴") === true || coloredBalls[i] === "🔵" || coloredBalls.includes("🔵") === true || coloredBalls[i] === "🟡" || coloredBalls.includes("🟡") === true)
        {
            redBalls = coloredBalls.filter((red) => {return red === "🔴"}).length;
            redBallEl.textContent = "🔴: " + redBalls
            blueBalls = coloredBalls.filter((blue) => {return blue === "🔵"}).length;
            blueBallEl.textContent = "🔵: " + blueBalls
            yellowBalls = coloredBalls.filter((yellow) => {return yellow === "🟡"}).length;
            yellowBallEl.textContent = "🟡: " + yellowBalls
        }
        else if (coloredBalls.includes("🔴") === false)
        {
            redBalls = 0;
            redBallEl.textContent = "🔴: " + redBalls;
        }
        else if (coloredBalls.includes("🔵") === false)
        {
            blueBalls = 0;
            blueBallEl.textContent = "🔵: " + redBalls;
        }
        else if (coloredBalls.includes("🟡") === false)
        {
            yellowBalls = 0;
            yellowBallEl.textContent = "🟡: " + redBalls;
        }
    }
}

randomBallBtn.addEventListener("click", function() {
    let getRandomNumber = Math.floor(Math.random() * coloredBalls.length);
    let randomBall = coloredBalls[getRandomNumber];

    coloredBalls.splice(getRandomNumber, 1);

    if (randomBall === undefined)
    {
        randomBallEl.textContent = "Random Ball: No balls";
    }
    else
    {
        randomBallEl.textContent = "Random Ball: " + randomBall;
    }

    countBalls();

    return;
});

addRedBtn.addEventListener("click", function() {
    redBalls++;
    let getRandomRedPosition = Math.floor(Math.random() * coloredBalls.length);
    coloredBalls.splice(getRandomRedPosition, 0, "🔴");
    countBalls();
    return;
});

addBlueBtn.addEventListener("click", function() {
    blueBalls++;
    let getRandomBluePosition = Math.floor(Math.random() * coloredBalls.length);
    coloredBalls.splice(getRandomBluePosition, 0, "🔵");
    countBalls();
    return;
});

addYellowBtn.addEventListener("click", function() {
    yellowBalls++;
    let getRandomYellowPosition = Math.floor(Math.random() * coloredBalls.length);
    coloredBalls.splice(getRandomYellowPosition, 0, "🟡");
    countBalls();
    return;
});
