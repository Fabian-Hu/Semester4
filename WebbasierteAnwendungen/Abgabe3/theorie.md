# Webbasierte Anwendungen Blatt 4

### Nennen sie die Kaskadierungs-Reihenfolge von CSS?

1. Browser
2. Extern und Intern (in Deklarations-Reihenfolge)
3. Inline

### Schreiben sie eine CSS-Selektor der das Element mit der id "sel" auswählt

```css
#sel {
	color: blue;
}

```

```html
<html>
	<head>
		<meta charset="UTF-8">
		<link rel="stylesheet" href="sel.css">
	</head>
	<body>
		<article id="sel">
			Der Text ist blau
		</article>
	</body>
</html>
```

