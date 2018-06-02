var lab7 = {
	applySettings: function (tableParams) {
		var color, image;

		switch (tableParams.color.value) {
			case 'white': {
				color = 'white';
				break;
			}
			case 'blue': {
				color = '#ADD8E6';
				break;
			}
			case 'yellow': {
				color = '#FFFFE0';
				break;
			}
			case 'green': {
				color = '#98FB98';
				break;
			}
			case 'gray': {
				color = '#CFCFCF';
				break;
			}
			case 'other': {
				color = tableParams.customColor.value;
				break;
			}
		}

		switch (tableParams.image.value) {
			case 'image1': {
				image = 'url("../images/bg02.png")';
				break;
			}
			case 'image2': {
				image = 'url("../images/bg03.png")';
				break;
			}
			case 'image3': {
				image = 'url("../images/bg04.png")';
				break;
			}
			case 'none': {
				image = 'none';
				break;
			}
		}

		if (tableParams.applySettings[0].checked) {
			var table = document.getElementById('myTable');

			table.style.backgroundColor = color;
			table.style.backgroundImage = image;
		} else {
			var columnNumber = parseInt(tableParams.columnNumber.value);
			var rowNumber = parseInt(tableParams.rowNumber.value);

			if(isNaN(columnNumber) || isNaN(rowNumber)) {
				alert('Введены некорректные данные!');
				return;
			}

			var rows = document.getElementById('myTable').getElementsByTagName('tr');
			var rowLength = rows[0].getElementsByTagName('th').length;

			if(columnNumber > rowLength || rowNumber > (rows.length - 1)) {
				alert('Введены некорректные данные!');
				return;
			}

			var cell = document.getElementById('myTable').getElementsByTagName('td')[rowLength * (rowNumber - 1) + columnNumber - 1];

			cell.style.backgroundColor = color;
			cell.style.backgroundImage = image;			
		}
	},
	checkApplySettings: function (tableParams) {
		var display;

		if (tableParams.applySettings[0].checked) {
			display = 'none';
			tableParams.rowNumber.value = '';
			tableParams.columnNumber.value = '';
		} else {
			display = 'block';
		}

		document.getElementById('cellChooser').style.display = display;
	},
	checkColor: function (tableParams) {
		var display;

		if (tableParams.color.value == 'other') {
			display = 'block';
		} else {
			display = 'none';
			tableParams.customColor.value = '';
		}

		document.getElementById('colorChooser').style.display = display;
	}
};
