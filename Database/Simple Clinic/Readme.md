# Create Relational Schema for the Clinic Database

This project involves designing a relational database schema for a simple clinic. Below are the detailed requirements for each entity.

---

## 1. Patients
The database should store information about patients, including:
- **Unique Identifier** (Patient ID)
- **Name**
- **Date of Birth**
- **Gender**
- **Contact Information** (Phone Number, Email)
- **Address**

---

## 2. Doctors
The database should store information about doctors, including:
- **Unique Identifier** (Doctor ID)
- **Name**
- **Specialization**
- **Date of Birth**
- **Gender**
- **Contact Information** (Phone Number, Email)
- **Address**

---

## 3. Appointments
The database should store information about appointments, including:
- **Unique Identifier** (Appointment ID)
- **Patient** (Linked to Patients table)
- **Doctor** (Linked to Doctors table)
- **Appointment Date and Time**
- **Appointment Status**:
  1. **Pending**: Scheduled but not yet occurred.
  2. **Confirmed**: Confirmed by both patient and doctor.
  3. **Completed**: Appointment took place as scheduled.
  4. **Canceled**: Canceled by either the patient or the doctor.
  5. **Rescheduled**: Rescheduled for a different date/time.
  6. **No Show**: Patient did not show up without canceling or rescheduling.

---

## 4. Medical Records
The database should store medical records for patients, including:
- **Unique Identifier** (Record ID)
- **Patient** (Linked to Patients table)
- **Doctor** (Linked to Doctors table)
- **Description of Visit**
- **Diagnosis**
- **Prescribed Medication**
- **Additional Notes**

> **Note:** Each attended appointment should have an associated medical record.

---

## 5. Prescriptions
The database should store prescription details, including:
- **Unique Identifier** (Prescription ID)
- **Medical Record** (Linked to Medical Records table)
- **Medication Name**
- **Dosage**
- **Frequency**
- **Start Date**
- **End Date**
- **Special Instructions**

> **Note:** Each medical record can have at most one prescription.

---

## 6. Payments
The database should store information about payments, including:
- **Unique Identifier** (Payment ID)
- **Patient** (Linked to Patients table)
- **Payment Date**
- **Payment Method**
- **Amount Paid**
- **Additional Notes**

> **Note:** Payments are linked to appointments.

---

## Solution
For a complete relational schema and solution, refer to the detailed [PDF documentation](./clinic-project.pdf).
