var myViewModel = {
    personName: ko.observable('Bob'),
    personAge: ko.observable(123)
};

window.onload = function() {
   ko.applyBindings(myViewModel);
}