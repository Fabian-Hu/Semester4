var myViewModel = {
    personName: 'Bob',
    personAge: 123
};

window.onload = function() {
   ko.applyBindings(myViewModel);
}