SELECT TOP 5 * FROM Patients AS Patient
FOR XML AUTO, ELEMENTS, ROOT('Patients')

--For storing the XML in the XML variable
DECLARE @Patients_XML XML = (SELECT TOP 5 * FROM Patients AS Patient FOR XML AUTO, ELEMENTS, ROOT('Patients'))
--For fetching the First Row Elements Patient Account and the Practice Code
SELECT Patient_Account = @Patients_XML.value('Patients[1]/Patient[1]/Patient_Account[1]', 'VARCHAR(50)'),
	   Practice_Code = @Patients_XML.value('Patients[1]/Patient[1]/Practice_Code[1]', 'VARCHAR(50)')

--For fetching the Second Row Elements Patient Account and the Practice Code
SELECT Patient_Account = @Patients_XML.value('Patients[1]/Patient[2]/Patient_Account[1]', 'VARCHAR(50)'),
	   Practice_Code = @Patients_XML.value('Patients[1]/Patient[2]/Practice_Code[1]', 'VARCHAR(50)')

--For fetching all the records with a header
SELECT 
	item.row.value('Patient_Account[1]', 'VARCHAR(100)') Patient_Account,
	item.row.value('Practice_Code[1]', 'VARCHAR(100)') Practice_Code
FROM @Patients_XML.nodes('Patients/Patient') item(row)