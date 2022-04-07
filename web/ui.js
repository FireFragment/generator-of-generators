
function Regenerate() {
    document.getElementById("generated").innerText = Generate(generator);

}

Regenerate();

document.addEventListener('keydown', function(e) {
    if (e.which == 32)
        Regenerate();
});
