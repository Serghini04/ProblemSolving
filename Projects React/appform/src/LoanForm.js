import React, { useState } from 'react';
import './FormStyles.css';
import SubmissionModal from './SubmissionModal';

export default function LoanForm() {
    const [formData, setFormData] = useState({
        name: '',
        phoneNumber: '',
        phone: '',
        isEmployee: false,
        salary: ''
    });
    
    const [showModal, setShowModal] = useState(false);

    const handleInputChange = (e) => {
        const { name, value, type, checked } = e.target;
        setFormData(prev => ({
            ...prev,
            [name]: type === 'checkbox' ? checked : value
        }));
    };

    const isFormValid = () => {
        return formData.name.trim() !== '' && 
               formData.phoneNumber.trim() !== '' && 
               formData.phone.trim() !== '' && 
               formData.salary !== '';
    };

    const handleSubmit = (e) => {
        e.preventDefault();
        if (isFormValid()) {
            setShowModal(true);
        }
    };

    const closeModal = () => {
        setShowModal(false);
    };

    return (
        <>
            <div className={`flex ${showModal ? 'hidden' : ''}`}>
                <form id='loan-form' className="form" onSubmit={handleSubmit}>
                    <h1>Requesting a Loan</h1>
                    <hr></hr>
                    
                    <label>Name:</label>
                    <input 
                        name="name"
                        value={formData.name}
                        onChange={handleInputChange}
                        required
                    />
                    
                    <label>Phone Number:</label>
                    <input 
                        name="phoneNumber"
                        value={formData.phoneNumber}
                        onChange={handleInputChange}
                        required
                    />
                    
                    <label>Phone:</label>
                    <input 
                        name="phone"
                        value={formData.phone}
                        onChange={handleInputChange}
                        required
                    />

                    <label style={{marginTop:"30px"}}>Are you an employee?</label>
                    <input 
                        type='checkbox' 
                        name="isEmployee"
                        checked={formData.isEmployee}
                        onChange={handleInputChange}
                    />
                    
                    <label>Salary:</label>
                    <select 
                        name="salary"
                        value={formData.salary}
                        onChange={handleInputChange}
                        required
                    >
                        <option value="">Select salary range</option>
                        <option value="less than 500$">less than 500$</option>
                        <option value="between 500$ and 2000$">between 500$ and 2000$</option>
                        <option value="above 2000$">above 2000$</option>
                    </select>

                    <button 
                        id='submit-load-btn' 
                        type="submit"
                        disabled={!isFormValid()}
                        style={{
                            opacity: isFormValid() ? 1 : 0.5,
                            cursor: isFormValid() ? 'pointer' : 'not-allowed'
                        }}
                    >
                        Submit
                    </button>
                </form>
            </div>
            
            {showModal && (
                <SubmissionModal 
                    formData={formData}
                    onClose={closeModal}
                />
            )}
        </>
    );
}
