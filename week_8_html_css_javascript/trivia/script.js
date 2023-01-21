const wrongBtn1 = document.getElementById("btn-wrong-choice-1");
const wrongBtn2 = document.getElementById("btn-wrong-choice-2");
const correctBtn = document.getElementById("btn-correct-choice");
const resultTxt1 = document.getElementById("txt-result1");

const answerInput = document.getElementById("input-answer");
const submitBtn = document.getElementById("btn-submit");
const resultTxt2 = document.getElementById("txt-result2");

wrongBtn1.addEventListener("click", function() {
    wrongBtn1.style.color = "red";
    resultTxt1.textContent = "Incorrect.";

    wrongBtn2.style.color = "black";
    correctBtn.style.color = "black";
});

wrongBtn2.addEventListener("click", function() {
    wrongBtn2.style.color = "red";
    resultTxt1.textContent = "Incorrect.";

    wrongBtn1.style.color = "black";
    correctBtn.style.color = "black";
});

correctBtn.addEventListener("click", function() {
    correctBtn.style.color = "green";
    resultTxt1.textContent = "Correct!";

    wrongBtn1.style.color = "black";
    wrongBtn2.style.color = "black";
});

submitBtn.addEventListener("click", function() {
    if ((answerInput.value === "DAVID") || (answerInput.value === "DAVID J. MALAN") || (answerInput.value === "MALAN")) {
        resultTxt2.textContent = "Correct!";
        answerInput.style.color = "green";
    } else {
        resultTxt2.textContent = "Incorrect.";
        answerInput.style.color = "red";
    }
})