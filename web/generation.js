const itemType = {
    text: 0,
    subgenerator: 1
}

var generator = JSON.parse(new URLSearchParams(window.location.search).get('generator'));

Array.prototype.randomItem = function () {
    return this[Math.floor((Math.random()*this.length))];
}

var generatedArr = [];

function TryNTimes(maxRetryCount, func) {
    for (var i = 0; i < maxRetryCount; i++){
        try {
            return func();
        } catch (err) {
            continue
        }
    }
    throw "Maximum number of retries (" + maxRetryCount + ") exceeded";
}

function Generate(generator) {
    try {
        return TryNTimes(30, function() {return GenerateSubgen(generator.main, generator, 0)});
    } catch (err) {
        throw "Recursive generator! (originally " + err + ")"
    }
}

function GenerateSubgen(subgenerator, parentGenerator, depth) {
    return subgenerator.opts.randomItem().items.map(item => GenerateItem(item, parentGenerator, depth + 1)).join("");
}

function GenerateItem(item, parentGenerator, depth) {
    if (depth > 300) {
        throw "Too deep recursion!";
    }
    switch (item.type) {
        case itemType.text: generatedArr.push(item); return item.value
        case itemType.subgenerator: return GenerateSubgen(parentGenerator.subgenerators.find(gen => gen.name == item.value), parentGenerator, depth + 1);
        default: console.error("Invalid generator: " + item.type + " is not type of an item!");
    }
}
