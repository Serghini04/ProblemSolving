import React from 'react';
import './ModalStyles.css';

const SubmissionModal = ({ formData, onClose }) => {
    const handleOverlayClick = (e) => {
        if (e.target === e.currentTarget) {
            onClose();
        }
    };

    return (
        <div className="modal-overlay" onClick={handleOverlayClick}>
            <div className="modal-content">
                <div className="modal-header">
                    <h2>Loan Application Submitted Successfully!</h2>
                    <button className="close-button" onClick={onClose}>×</button>
                </div>
                
                <div className="modal-body">
                    <div className="success-icon">✓</div>
                    <p className="success-message">
                        Thank you for your loan application. We have received your information and will review it shortly.
                    </p>
                    
                    <div className="submitted-info">
                        <h3>Submitted Information:</h3>
                        <div className="info-item">
                            <strong>Name:</strong> {formData.name}
                        </div>
                        <div className="info-item">
                            <strong>Phone Number:</strong> {formData.phoneNumber}
                        </div>
                        <div className="info-item">
                            <strong>Phone:</strong> {formData.phone}
                        </div>
                        <div className="info-item">
                            <strong>Employee Status:</strong> {formData.isEmployee ? 'Yes' : 'No'}
                        </div>
                        <div className="info-item">
                            <strong>Salary Range:</strong> {formData.salary}
                        </div>
                    </div>
                    
                    <p className="next-steps">
                        We will contact you within 2-3 business days with an update on your application status.
                    </p>
                </div>
                
                <div className="modal-footer">
                    <button className="ok-button" onClick={onClose}>OK</button>
                </div>
            </div>
        </div>
    );
};

export default SubmissionModal;