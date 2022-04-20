// Homepage of the project
const homepage = "https://github.com/FireFragment/generator-of-generators"

function Regenerate() {
    try {
        document.getElementById("generated").innerText = Generate(generator);
    } catch (err) {
        alert("You've got broken link!\n\nDetailed information:\n" + err);
    }
}

// Redirect to homepage when there's no generator
if (!generator)
    window.location.href = homepage;
Regenerate();

document.addEventListener('keydown', function(e) {
    if (e.which == 32)
        Regenerate();
});

document.addEventListener('click', function() {
    console.log("klikd");
    Regenerate();
});
