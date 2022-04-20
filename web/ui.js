
function Regenerate() {
    try {
        document.getElementById("generated").innerText = Generate(generator);
    } catch (err) {
        alert("You've got broken link!\n\nDetailed information:\n" + err);
    }
}

Regenerate();

document.addEventListener('keydown', function(e) {
    if (e.which == 32)
        Regenerate();
});

document.addEventListener('click', function() {
    console.log("klikd");
    Regenerate();
});
