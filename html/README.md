# HTML (HyperText Markup Language)

## Introduction

### Tags

`Html` is made up of tags. It consists of an opening `<tag>` and a closing `</tag>`. In between each tag is the content

```html
<body>content</body>
```

Each tag is broken down into elemets.

Structural Elements
- `<html>` - warps everythings
- `<head>` - metadata (title, links to CSS, SEO info).
- `<body>` - everything the user sees
- `<main>`

Heading And Text
- `<h1>` to `<h6>` - headings (h1 = biggest going down... h6)
- `<p>` - paragraph
- `<span>` - inline container (no line break).
- `<br>` - line break.

Grouping Content
- `<div>`
- `<section>`
- `<article>`
- `<nav>`
- `<header>`
- `<footer>`
- `<aside>`

Lists
- `<ul>` - unorder list (bullets).
- `<ol>` - ordered list (numbers).
- `<li>` - list item

Html Document Starts Like This:
```html
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>My HTML</title>
	<!-- This is a comment in HTML -->
	<link rel="stylesheet" href="style.css">
	<!-- Can be 
		multi-line also  -->
</head>
	<body>
		<main class="from-css">
			<h1>First Header</h1>
				<p>Random Content</p>

		</main>
	</body>
</head>
</html>
```

