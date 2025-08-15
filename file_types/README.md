# MD (Markdown) XML (Extensible Markup Language) JSON (JavaScript Object Notation)

## Introduction

JSON or JavaScript Object Notation it is a light weight human readable format to store data and exchange data. It uses the idea of key value pairs to match a `key` to a `value`. 

The idea of a `key` followed by a `value` so also known as a _dictionary_. To find the information specific information on a key

The extension type for each of these files are:

- MD (Markdown) - `.md`
- XML (Extensible Markup Language) - `.xml`
- JSON (JavaScript Object Notation) - `.json`

### Data Types

MD
---

Notation:

To have a empty line between each paragraph just include a empty line between each paragraph.

Example:
```md
This is a paragraph.

There is a space between this line and the paragraph above.
```

Headings:

- Include a `#` to make a header. There are 6 different heading types where the number of `#` is the heading number, with one `#` is the largest.

Code:

- To make something a block of code just include 2 tick \` \` marks and within it write the block of code

Italics and Bold: 

- To make something italics just add one * and another * between some text
- To make something bold jsut add two ** and another ** between some text

Links:

- To add links just use `[`text`]`(link) to make a link

Images:

- To add a image just use !`[`alt-test`]`(picture-url) where alt-text is the images alternate text. Where the link could be remote or local

Unordered Lists:

- To make a unorder lists start it with a `-` or a `*`

Ordered Lists:

- To make a order list start it with a number `1` followed by a period `.`

XML 
---

The key could be any type of data type. Those key data types are:

- Strings

Information is represented with tags `<></>`. The opening tag is `<>` and the close tag is `</>`.

The content within the tag is between the opening and closing tag. `<tag>`this is content`</tag>`

The content wihthin the tag is treated as a string

Tags can also have **Attributes**. They are key value pairs. But the keys dont have quotes around it

`<tag key="value"> content</tag>`

XML is used to indicate some property about the data (metadata).

Example:
```xml
<fileSize unit="kB">34.6</fileSize>

<cost currency="USD">43.33</cost>
```

- cost = tag
- currency = attribute
- 43.33 = content

If there is no content within a tag they can also be represented by:
```xml
`<person name="Jarron" />`
```

Notice there is no extra tag called `</person>` this is because there is no content within the tag so therefore it is not needed.

You can also include a namespace by doing `<namespace:education>`

JSON
---

The key could be any type of data type. Those key data types are:

- Strings - To define a string include the key + the string in quotes
- Numbers - To define a number include the key + number not in quotes
- Booleans - To define 
- None - To define 
- Arrays - To define an array, it is enclosed in `[` brackets `]`.
- Object (dictionaries) - To define an object, it is enclosed in `{` braces `}`.

The notation is that all keys are enclosed in `""` like such `"name"`

EXAMPLE:
```json
{
   "name": "Jarron",
   "age": 29,
   "height": 5.8,
   "weight": 158,
   "schools": [ "Great Oak Highschool","California State University, Fullerton" ],
   "hasBachelors": true
}
```

