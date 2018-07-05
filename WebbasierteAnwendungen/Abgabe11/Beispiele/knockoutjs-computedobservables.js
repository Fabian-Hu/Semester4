function myViewModel() {
    this.personName = ko.observable('Bob'),
    this.personAge = ko.observable(123),
	this.personDogAge = ko.computed(function() {		
		return this.personAge() * 7;
	}, this)
};

window.onload = function() {
   ko.applyBindings(myViewModel);
}